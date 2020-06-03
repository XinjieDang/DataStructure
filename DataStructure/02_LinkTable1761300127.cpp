#include<iostream>
using namespace std;
typedef int DataType;
#define ERROR NULL
//定义节点类型
struct Node
{
public:
	DataType data; //数据域
	Node* next; //指针域
};
//构建一个单链表类

int index = 1;
class LinkList
{
public:
	LinkList();                  //构建一个单链表;    
	~LinkList(); //销毁一个单链表;    
	void CreateLinkList(int n); //创建一个单链表   
	void TravalLinkList(); //遍历线性表   
	int GetLength(); //获取线性表长度 
	bool IsEmpty(); //判断单链表是否为空
	Node* Find(DataType data); //查找节点  
	void InsertElemAtEnd(DataType data); //在尾部插入指定的元素    
	void InsertElemAtIndex(DataType data, int n); //在指定位置插入指定元素   
	void InsertElemAtHead(DataType data); //在头部插入指定元素 
	void DeleteElemAtEnd(); //在尾部删除元素
	void DeleteAll(); //删除所有数据  
	void DeleteElemAtPoint(DataType data); //删除指定的数据    
	void DeleteElemAtHead(); //在头部删除节点
	void sort_list(Node* pHead);//冒泡排序
	void sort_insert(Node* pHead);//插入排序
private:
	Node* head; //头结点
};
//初始化单链表
LinkList::LinkList()
{
	head = new Node;
	head->data = 0; //将头结点的数据域定义为0
	head->next = NULL; //头结点的下一个定义为NULL
}
//销毁单链表
LinkList::~LinkList()
{
	Node* q = head->next; //定义q指向空白头结点的下一个
	while (q != NULL) //当指针的地址不为空时
	{
		head->next = q->next; //让q所指向的结点从链表中脱离出来，并保持原链表的链不断开
		delete q;//释放从链表中脱离出来的结点的空间
		q = head->next;//q之前指向的结点已被删除，现在需要重新给q赋值
	}
	delete head; //其余结点已被删完，最后删除空白头结点
}
//创建一个单链表
void LinkList::CreateLinkList(int n)
{
	Node* pnew, * ptemp;
	ptemp = head;

	if (n < 0)
	{ //当输入的值有误时，处理异常      
		cout << "输入的节点个数有误" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++)
	{ //将值一个一个插入单链表中pnew = new Node;        
		cout << "请输入第" << i + 1 << "个值: ";
		pnew = new Node;
		cin >> pnew->data;
		pnew->next = NULL; //新节点的下一个地址为NULL  
		ptemp->next = pnew; //当前结点的下一个地址设为新节点 
		ptemp = pnew; //将当前结点设为新节点    
	}
}

//遍历单链表
void LinkList::TravalLinkList()
{
	if (head == NULL || head->next == NULL)
	{
		cout << "链表为空表" << endl;
	}
	Node* p = head; //另指针指向头结点    
	while (p->next != NULL) //当指针的下一个地址不为空时，循环输出p的数据域   
	{
		p = p->next; //p指向p的下一个地址     
		cout << p->data << "  |  ";
	}
	cout << endl;
}
//获取单链表的长度
int LinkList::GetLength()
{
	int count = 0; //定义count计数
	Node* p = head->next; //定义p指向头结点
	while (p != NULL) //当指针的下一个地址不为空时，count+1  
	{
		count++;
		p = p->next; //p指向p的下一个地址
	}
	return count; //返回count的数据
}
//判断单链表是否为空
bool LinkList::IsEmpty()
{
	if (head->next == NULL)
		return true;
	else
		return false;
}
//查找节点
Node* LinkList::Find(DataType data)
{
	
	Node* p = head->next;
	if (p == NULL) { //当为空表时，报异常      
		cout << "此链表为空链表" << endl;
		return ERROR;
	}
	else
	{
		while (p != NULL) //循环每一个节点      
		{
			if (p->data == data)
			{
				return p; //返回指针域
			}
			p = p->next;
			index++;
		}
		return NULL; //未查询到结
	}
}
//在尾部插入指定的元素
void LinkList::InsertElemAtEnd(DataType data)
{
	Node* newNode = new Node; //定义一个Node结点指针newNode 
	newNode->next = NULL; //定义newNode的数据域和指针域  
	newNode->data = data;
	Node* p = head; //定义指针p指向头结点
	if (head == NULL)
	{ //当头结点为空时，设置newNode为头结点        
		head = newNode;
	}
	else //循环知道最后一个节点，将newNode放置在最后
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newNode;
	}
	sort_list(head);
}
//在指定位置插入指定元素
void LinkList::InsertElemAtIndex(DataType data, int n)
{
	if (n<1 || n>GetLength() + 1) //输入有误报异常        
		cout << "输入的值错误" << endl;
	else
	{
		Node* ptemp = new Node; //创建一个新的节点       
		ptemp->data = data; //定义数据域 
		Node* p = head; //创建一个指针指向头结点       
		int i = 1;
		while (n > i) //遍历到指定的位置   
		{
			p = p->next;
			i++;
		}
		ptemp->next = p->next; //将新节点插入到指定位置      
		p->next = ptemp;
		sort_list(head);
	}
}
//在头部插入指定元素
void LinkList::InsertElemAtHead(DataType data)
{
	Node* newNode = new Node; //定义一个Node结点指针newNode 
	newNode->data = data;
	Node* p = head; //定义指针p指向头结点 
	if (head == NULL)
	{ //当头结点为空时，设置newNode为头结点
		head = newNode;
	}
	newNode->next = p->next; //将新节点插入到指定位置    
	p->next = newNode;
	//sort_list(head);
	sort_insert(head);
}
//在尾部删除元素
void LinkList::DeleteElemAtEnd()
{
	Node* p = head; //创建一个指针指向头结点    
	Node* ptemp = NULL; //创建一个占位节点
	if (p->next == NULL)
	{ //判断链表是否为空       
		cout << "单链表空" << endl;
	}
	else
	{
		while (p->next != NULL) //循环到尾部的前一个
		{
			ptemp = p; //将ptemp指向尾部的前一个节点         
			p = p->next; //p指向最后一个节点
		}
		delete p; //删除尾部节点        
		p = NULL;
		ptemp->next = NULL;
	}
}
//删除所有数据
void LinkList::DeleteAll()
{
	Node* p = head->next;
	Node* ptemp = new Node;
	while (p != NULL) //在头结点的下一个节点逐个删除节点
	{
		ptemp = p;
		p = p->next;
		head->next = p;
		ptemp->next = NULL;
		delete ptemp;
	}
	head->next = NULL; //头结点的下一个节点指向NULL
}
//删除指定的数据
void LinkList::DeleteElemAtPoint(DataType data)
{
	Node* ptemp = Find(data); //查找到指定数据的节点位置    
	if (ptemp == head->next)
	{ //判断是不是头结点的下一个节点，如果是就从头部删了它              
		DeleteElemAtHead();
	}
	else
	{
		Node* p = head; //p指向头结点 
		while (p->next != ptemp) //p循环到指定位置的前一个节点      
		{
			p = p->next;
		}
		p->next = ptemp->next; //删除指定位置的节点    
		delete ptemp;
		ptemp = NULL;
	}
}
//在头部删除节点
void LinkList::DeleteElemAtHead()
{
	Node* p = head;
	if (p == NULL || p->next == NULL)
	{ //判断是否为空表，报异常   
		cout << "该链表为空表" << endl;
	}
	else
	{
		Node* ptemp = NULL; //创建一个占位节点    
		p = p->next;
		ptemp = p->next; //将头结点的下下个节点指向占位节点  
		delete p; //删除头结点的下一个节点    
		p = NULL;
		head->next = ptemp; //更换头结点的指针域 
	}
}



void  LinkList::sort_list(Node* pHead)//冒泡排序
{
	Node* p, * q;
	DataType temp;
	for (p = pHead->next; p != NULL; p = p->next)
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->data > q->data)
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
}



void  LinkList::sort_insert(Node* pHead)//插入排序
{
	Node* p, * pre ,* q;
	p = pHead->next->next;//指向第二个结点元素
	pHead->next ->next = NULL;//构造只有一个数据元素的链表
	while (p->next != NULL)
	{
		q = p->next;//保存 p结点后的元素指针
		pre = pHead;//从头结点开始比较
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
			p->next = pre->next;
			pre->next = p;
			p = q;
	}
}


//测试函数
int main()
{
	LinkList l;
	int i;
	do {
		cout << "*******************\n1.创建单链表\n2.遍历单链表\n3.获取单链表的长度\n4.判断单链表是否为空\n5.查找节点\n";
		cout << "6.在尾部插入指定元素\n7.在指定位置插入指定元素\n8.在头部插入指定元素\n";
		cout << "9.在尾部删除元素\n10.删除所有元素\n11.删除指定元素\n12.在头部删除元素\n0.退出\n*******************" << endl;
		cout << "请输入要执行的操作: ";
		cin >> i;
		switch (i) {
		case 1:
			int n;
			cout << "请输入单链表的长度: ";
			cin >> n;
			l.CreateLinkList(n);
			break;
		case 2:
			l.TravalLinkList();
			break;
		case 3:
			cout << "该单链表的长度为" << l.GetLength() << endl;
			break;
		case 4:
			if (l.IsEmpty() == 1)
				cout << "该单链表是空表" << endl;
			else
				cout << "该单链表不是空表" << endl;
			break;
		case 5:
			DataType data;
			cout << "请输入要查找节点的值: ";
			cin >> data;
			if (l.Find(data)){
				cout << "链表中存在该节点" << endl;
				cout << "该元素的位置为:" << index << endl;
			}
			else
				cout << "链表中找不到该节点" << endl;
			break;
		case 6:
			DataType endData;
			cout << "请输入要在尾部插入的值: ";
			cin >> endData;
			l.InsertElemAtEnd(endData);
			break;
		case 7:
			DataType pointData;
			int index;
			cout << "请输入要插入的数据: ";
			cin >> pointData;
			cout << "请输入要插入数据的位置: ";
			cin >> index;
			l.InsertElemAtIndex(pointData, index);
			break;
		case 8:
			DataType headData;
			cout << "请输入要在头部插入的值: ";
			cin >> headData;
			l.InsertElemAtHead(headData);
			break;
		case 9:
			l.DeleteElemAtEnd();
			break;
		case 10:
			l.DeleteAll();
			break;
		case 11:
			DataType pointDeleteData;
			cout << "请输入要删除的数据: ";
			cin >> pointDeleteData;
			l.DeleteElemAtPoint(pointDeleteData);
			break;
		case 12:
			l.DeleteElemAtHead();
			break;
		default: break;
		}//end switch
	} while (i != 0);    //end do-while
	system("pause");
	return 0;
}
