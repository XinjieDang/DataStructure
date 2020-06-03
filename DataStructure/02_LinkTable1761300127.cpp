#include<iostream>
using namespace std;
typedef int DataType;
#define ERROR NULL
//����ڵ�����
struct Node
{
public:
	DataType data; //������
	Node* next; //ָ����
};
//����һ����������

int index = 1;
class LinkList
{
public:
	LinkList();                  //����һ��������;    
	~LinkList(); //����һ��������;    
	void CreateLinkList(int n); //����һ��������   
	void TravalLinkList(); //�������Ա�   
	int GetLength(); //��ȡ���Ա��� 
	bool IsEmpty(); //�жϵ������Ƿ�Ϊ��
	Node* Find(DataType data); //���ҽڵ�  
	void InsertElemAtEnd(DataType data); //��β������ָ����Ԫ��    
	void InsertElemAtIndex(DataType data, int n); //��ָ��λ�ò���ָ��Ԫ��   
	void InsertElemAtHead(DataType data); //��ͷ������ָ��Ԫ�� 
	void DeleteElemAtEnd(); //��β��ɾ��Ԫ��
	void DeleteAll(); //ɾ����������  
	void DeleteElemAtPoint(DataType data); //ɾ��ָ��������    
	void DeleteElemAtHead(); //��ͷ��ɾ���ڵ�
	void sort_list(Node* pHead);//ð������
	void sort_insert(Node* pHead);//��������
private:
	Node* head; //ͷ���
};
//��ʼ��������
LinkList::LinkList()
{
	head = new Node;
	head->data = 0; //��ͷ������������Ϊ0
	head->next = NULL; //ͷ������һ������ΪNULL
}
//���ٵ�����
LinkList::~LinkList()
{
	Node* q = head->next; //����qָ��հ�ͷ������һ��
	while (q != NULL) //��ָ��ĵ�ַ��Ϊ��ʱ
	{
		head->next = q->next; //��q��ָ��Ľ������������������������ԭ����������Ͽ�
		delete q;//�ͷŴ���������������Ľ��Ŀռ�
		q = head->next;//q֮ǰָ��Ľ���ѱ�ɾ����������Ҫ���¸�q��ֵ
	}
	delete head; //�������ѱ�ɾ�꣬���ɾ���հ�ͷ���
}
//����һ��������
void LinkList::CreateLinkList(int n)
{
	Node* pnew, * ptemp;
	ptemp = head;

	if (n < 0)
	{ //�������ֵ����ʱ�������쳣      
		cout << "����Ľڵ��������" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++)
	{ //��ֵһ��һ�����뵥������pnew = new Node;        
		cout << "�������" << i + 1 << "��ֵ: ";
		pnew = new Node;
		cin >> pnew->data;
		pnew->next = NULL; //�½ڵ����һ����ַΪNULL  
		ptemp->next = pnew; //��ǰ������һ����ַ��Ϊ�½ڵ� 
		ptemp = pnew; //����ǰ�����Ϊ�½ڵ�    
	}
}

//����������
void LinkList::TravalLinkList()
{
	if (head == NULL || head->next == NULL)
	{
		cout << "����Ϊ�ձ�" << endl;
	}
	Node* p = head; //��ָ��ָ��ͷ���    
	while (p->next != NULL) //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����p��������   
	{
		p = p->next; //pָ��p����һ����ַ     
		cout << p->data << "  |  ";
	}
	cout << endl;
}
//��ȡ������ĳ���
int LinkList::GetLength()
{
	int count = 0; //����count����
	Node* p = head->next; //����pָ��ͷ���
	while (p != NULL) //��ָ�����һ����ַ��Ϊ��ʱ��count+1  
	{
		count++;
		p = p->next; //pָ��p����һ����ַ
	}
	return count; //����count������
}
//�жϵ������Ƿ�Ϊ��
bool LinkList::IsEmpty()
{
	if (head->next == NULL)
		return true;
	else
		return false;
}
//���ҽڵ�
Node* LinkList::Find(DataType data)
{
	
	Node* p = head->next;
	if (p == NULL) { //��Ϊ�ձ�ʱ�����쳣      
		cout << "������Ϊ������" << endl;
		return ERROR;
	}
	else
	{
		while (p != NULL) //ѭ��ÿһ���ڵ�      
		{
			if (p->data == data)
			{
				return p; //����ָ����
			}
			p = p->next;
			index++;
		}
		return NULL; //δ��ѯ����
	}
}
//��β������ָ����Ԫ��
void LinkList::InsertElemAtEnd(DataType data)
{
	Node* newNode = new Node; //����һ��Node���ָ��newNode 
	newNode->next = NULL; //����newNode���������ָ����  
	newNode->data = data;
	Node* p = head; //����ָ��pָ��ͷ���
	if (head == NULL)
	{ //��ͷ���Ϊ��ʱ������newNodeΪͷ���        
		head = newNode;
	}
	else //ѭ��֪�����һ���ڵ㣬��newNode���������
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newNode;
	}
	sort_list(head);
}
//��ָ��λ�ò���ָ��Ԫ��
void LinkList::InsertElemAtIndex(DataType data, int n)
{
	if (n<1 || n>GetLength() + 1) //���������쳣        
		cout << "�����ֵ����" << endl;
	else
	{
		Node* ptemp = new Node; //����һ���µĽڵ�       
		ptemp->data = data; //���������� 
		Node* p = head; //����һ��ָ��ָ��ͷ���       
		int i = 1;
		while (n > i) //������ָ����λ��   
		{
			p = p->next;
			i++;
		}
		ptemp->next = p->next; //���½ڵ���뵽ָ��λ��      
		p->next = ptemp;
		sort_list(head);
	}
}
//��ͷ������ָ��Ԫ��
void LinkList::InsertElemAtHead(DataType data)
{
	Node* newNode = new Node; //����һ��Node���ָ��newNode 
	newNode->data = data;
	Node* p = head; //����ָ��pָ��ͷ��� 
	if (head == NULL)
	{ //��ͷ���Ϊ��ʱ������newNodeΪͷ���
		head = newNode;
	}
	newNode->next = p->next; //���½ڵ���뵽ָ��λ��    
	p->next = newNode;
	//sort_list(head);
	sort_insert(head);
}
//��β��ɾ��Ԫ��
void LinkList::DeleteElemAtEnd()
{
	Node* p = head; //����һ��ָ��ָ��ͷ���    
	Node* ptemp = NULL; //����һ��ռλ�ڵ�
	if (p->next == NULL)
	{ //�ж������Ƿ�Ϊ��       
		cout << "�������" << endl;
	}
	else
	{
		while (p->next != NULL) //ѭ����β����ǰһ��
		{
			ptemp = p; //��ptempָ��β����ǰһ���ڵ�         
			p = p->next; //pָ�����һ���ڵ�
		}
		delete p; //ɾ��β���ڵ�        
		p = NULL;
		ptemp->next = NULL;
	}
}
//ɾ����������
void LinkList::DeleteAll()
{
	Node* p = head->next;
	Node* ptemp = new Node;
	while (p != NULL) //��ͷ������һ���ڵ����ɾ���ڵ�
	{
		ptemp = p;
		p = p->next;
		head->next = p;
		ptemp->next = NULL;
		delete ptemp;
	}
	head->next = NULL; //ͷ������һ���ڵ�ָ��NULL
}
//ɾ��ָ��������
void LinkList::DeleteElemAtPoint(DataType data)
{
	Node* ptemp = Find(data); //���ҵ�ָ�����ݵĽڵ�λ��    
	if (ptemp == head->next)
	{ //�ж��ǲ���ͷ������һ���ڵ㣬����Ǿʹ�ͷ��ɾ����              
		DeleteElemAtHead();
	}
	else
	{
		Node* p = head; //pָ��ͷ��� 
		while (p->next != ptemp) //pѭ����ָ��λ�õ�ǰһ���ڵ�      
		{
			p = p->next;
		}
		p->next = ptemp->next; //ɾ��ָ��λ�õĽڵ�    
		delete ptemp;
		ptemp = NULL;
	}
}
//��ͷ��ɾ���ڵ�
void LinkList::DeleteElemAtHead()
{
	Node* p = head;
	if (p == NULL || p->next == NULL)
	{ //�ж��Ƿ�Ϊ�ձ����쳣   
		cout << "������Ϊ�ձ�" << endl;
	}
	else
	{
		Node* ptemp = NULL; //����һ��ռλ�ڵ�    
		p = p->next;
		ptemp = p->next; //��ͷ�������¸��ڵ�ָ��ռλ�ڵ�  
		delete p; //ɾ��ͷ������һ���ڵ�    
		p = NULL;
		head->next = ptemp; //����ͷ����ָ���� 
	}
}



void  LinkList::sort_list(Node* pHead)//ð������
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



void  LinkList::sort_insert(Node* pHead)//��������
{
	Node* p, * pre ,* q;
	p = pHead->next->next;//ָ��ڶ������Ԫ��
	pHead->next ->next = NULL;//����ֻ��һ������Ԫ�ص�����
	while (p->next != NULL)
	{
		q = p->next;//���� p�����Ԫ��ָ��
		pre = pHead;//��ͷ��㿪ʼ�Ƚ�
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
			p->next = pre->next;
			pre->next = p;
			p = q;
	}
}


//���Ժ���
int main()
{
	LinkList l;
	int i;
	do {
		cout << "*******************\n1.����������\n2.����������\n3.��ȡ������ĳ���\n4.�жϵ������Ƿ�Ϊ��\n5.���ҽڵ�\n";
		cout << "6.��β������ָ��Ԫ��\n7.��ָ��λ�ò���ָ��Ԫ��\n8.��ͷ������ָ��Ԫ��\n";
		cout << "9.��β��ɾ��Ԫ��\n10.ɾ������Ԫ��\n11.ɾ��ָ��Ԫ��\n12.��ͷ��ɾ��Ԫ��\n0.�˳�\n*******************" << endl;
		cout << "������Ҫִ�еĲ���: ";
		cin >> i;
		switch (i) {
		case 1:
			int n;
			cout << "�����뵥����ĳ���: ";
			cin >> n;
			l.CreateLinkList(n);
			break;
		case 2:
			l.TravalLinkList();
			break;
		case 3:
			cout << "�õ�����ĳ���Ϊ" << l.GetLength() << endl;
			break;
		case 4:
			if (l.IsEmpty() == 1)
				cout << "�õ������ǿձ�" << endl;
			else
				cout << "�õ������ǿձ�" << endl;
			break;
		case 5:
			DataType data;
			cout << "������Ҫ���ҽڵ��ֵ: ";
			cin >> data;
			if (l.Find(data)){
				cout << "�����д��ڸýڵ�" << endl;
				cout << "��Ԫ�ص�λ��Ϊ:" << index << endl;
			}
			else
				cout << "�������Ҳ����ýڵ�" << endl;
			break;
		case 6:
			DataType endData;
			cout << "������Ҫ��β�������ֵ: ";
			cin >> endData;
			l.InsertElemAtEnd(endData);
			break;
		case 7:
			DataType pointData;
			int index;
			cout << "������Ҫ���������: ";
			cin >> pointData;
			cout << "������Ҫ�������ݵ�λ��: ";
			cin >> index;
			l.InsertElemAtIndex(pointData, index);
			break;
		case 8:
			DataType headData;
			cout << "������Ҫ��ͷ�������ֵ: ";
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
			cout << "������Ҫɾ��������: ";
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
