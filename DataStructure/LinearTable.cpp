#include<iostream>
using namespace std;
typedef int DataType;
enum Status { SUCCESS, FAIL, RANGE_ERROR, OVER_FLOW, EMPTY };
//定义结点类型
struct Node
{//线性表 链式存储
public:
	DataType data; //数据域
	Node* next; //指针域
};
//构建一个单链表类
class LinkList
{
public:
	LinkList();     //构建一个单链表;    
	~LinkList(); //销毁一个单链表;    
	void TravalLinkList(); //遍历线性表   
	int GetLength(); //获取线性表长度 
	int  LocateData(const DataType& data) const;
	Status  GetData(int i, DataType& data) const;
	Status  InsertElemAtIndex(int i, const DataType& data);
	Status  DeleteElemAtIndex(int i, DataType& data);

private:
	Node* head; //头指针
	int  length;
};
//初始化单链表创建空白头结点
LinkList::LinkList()
{
	head = new Node;
	head->data = 0; //将头结点的数据域定义为0
	head->next = NULL; //头结点的下一个定义为NULL
	length = 0;
}
//销毁单链表
LinkList::~LinkList()
{
	Node* p = head;
	Node* delep;
	while (p)
	{
		p = p->next;
		delep = p;
		delete delep;
	}
	delete head;
	length = 0;
}

int main(int argc, char** argv)
{
	LinkList* sl = new LinkList();
	DataType data = 1;
	DataType& item = data;
	int index = 0;
	for (int i = 1; i < 6; i++)
	{
		cout << "请输入要插入的第" << i << "个数!" << " ";
		cin >> data;
	    item = data;
		cout << "请输入该数的插入位置!" << " ";
		cin >> index;
		sl->InsertElemAtIndex(index, item);
	}
	int num = sl->GetLength();
	sl->TravalLinkList();
	cout << endl;
	cout << "成功执行！链表长度为:" << num << endl;
	data = 1;        //数据重置
	num = 1;
	index = 0;
	cout << endl;
	cout << "请输入要查找的节点值,返回改节点位置：";
	cin >> data;
	item = data;
	num=sl->LocateData(item);
	cout << "成功,该节点位置为：" << num << endl;
	cout << "查找指定节点的值，请输入节点的位置和节点：";
	cin >> index;
	cin >> data;
    item= data;
	if (sl->GetData(index, item) == 0)
		cout <<"SUCCESS" << endl;
	for (int j = 1; j < 3; j++)
	{
		cout << "请输入要删除的第" << j << "个位置的数!" << " ";
		cin >> data;
	    item = data;
		cout << "请输入该数的位置!" << " ";
		cin >> index;
		sl->DeleteElemAtIndex(index, item);
		sl->TravalLinkList();
		num = sl->GetLength();
		cout << endl;
		cout << "成功执行！链表长度为:" << num << endl;
	}
	return 0;
}


//遍历单链表
void LinkList::TravalLinkList()
{

	Node* p = head->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;

	}
}
//获取单链表的长度
int LinkList::GetLength()
{
	Node* p = head->next;
	int i = 1;
	if (p == NULL)
	{
		return FAIL;
	}
	while (p)
	{
		p = p->next;
		i++;

	}
	return i;
}

//查找结点data
int  LinkList::LocateData(const DataType& data) const
{
	Node* p = head->next;
	int count = 1;
	while (p != NULL)
	{
		if (data == p->data) {
			return count;
			break;     //找到
		}	
		else
		{
			p = p->next;               //指针移动继续找下一个
			count++;
		}
		if (p != NULL)return count;    //找到，返回找到的位置
		else return -1;
	}


}
//查找第i个结点
Status  LinkList::GetData(int i, DataType& data) const
{
	Node* p = head->next;
	int count = 1;
	if (i<1 || i>length)
		return FAIL;
	else
	{
		while (count < i)
		{
			count++;
			p = p->next;

		}
		if (p != NULL && count == i)
		{
			data = p->data;
			return SUCCESS;
		}

	}

}
//在指定位置插入指定元素
Status LinkList::InsertElemAtIndex(int i, const DataType& data)
{
	Node* p = head;
	int index = 1;
	if (i < 0 || i> length + 1) { //判断插入位置
		cout << "插入的位置错误！" << endl;
		return FAIL;
	}
	else
	{
		while (index < i - 1)       //指针移动到插入的前一个节点
		{
			p = p->next;
			index++;
		}
		Node* newp = new Node;  //新的节点
		newp->next = p->next;   //新的节点指向插入位置元素
		newp->data = data;      //要插入的数据赋值给新节点的data
		p->next = newp;         //插入位置的前一个节点的next指向新节点
		length++;
		return SUCCESS;
	}
	return FAIL;
}

//删除指定的数据
Status LinkList::DeleteElemAtIndex(int i, DataType& data)
{
	Node* p = head;
	if (i<1 || i>length) return FAIL;            //删除位置超出范围
	int index = 1;  //指针位置
	while (index <= i - 1)                         //指针移动到指定节点的前一个节点
	{
		p = p->next;
		index++;
	}
	Node* rmp = p->next;                       //要删除的节点用rmp保存
	if (rmp->data == data && rmp->next != NULL) //删除的数据正确和删除节点的next不为空
	{
		p->next = rmp->next;                   //要删除节点的前一个节点指向删除节点的next
		delete rmp;
		length--;
		return SUCCESS;
	}
	if (length == 1 && rmp->data == data)
	{
		delete rmp;
		length--;
		return SUCCESS;
	}
}


