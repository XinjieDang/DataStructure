#include<iostream>
using namespace std;
typedef int DataType;
enum Status { SUCCESS, FAIL, RANGE_ERROR, OVER_FLOW, EMPTY };
//����������
struct Node
{//���Ա� ��ʽ�洢
public:
	DataType data; //������
	Node* next; //ָ����
};
//����һ����������
class LinkList
{
public:
	LinkList();     //����һ��������;    
	~LinkList(); //����һ��������;    
	void TravalLinkList(); //�������Ա�   
	int GetLength(); //��ȡ���Ա��� 
	int  LocateData(const DataType& data) const;
	Status  GetData(int i, DataType& data) const;
	Status  InsertElemAtIndex(int i, const DataType& data);
	Status  DeleteElemAtIndex(int i, DataType& data);

private:
	Node* head; //ͷָ��
	int  length;
};
//��ʼ�����������հ�ͷ���
LinkList::LinkList()
{
	head = new Node;
	head->data = 0; //��ͷ������������Ϊ0
	head->next = NULL; //ͷ������һ������ΪNULL
	length = 0;
}
//���ٵ�����
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
		cout << "������Ҫ����ĵ�" << i << "����!" << " ";
		cin >> data;
	    item = data;
		cout << "����������Ĳ���λ��!" << " ";
		cin >> index;
		sl->InsertElemAtIndex(index, item);
	}
	int num = sl->GetLength();
	sl->TravalLinkList();
	cout << endl;
	cout << "�ɹ�ִ�У�������Ϊ:" << num << endl;
	data = 1;        //��������
	num = 1;
	index = 0;
	cout << endl;
	cout << "������Ҫ���ҵĽڵ�ֵ,���ظĽڵ�λ�ã�";
	cin >> data;
	item = data;
	num=sl->LocateData(item);
	cout << "�ɹ�,�ýڵ�λ��Ϊ��" << num << endl;
	cout << "����ָ���ڵ��ֵ��������ڵ��λ�úͽڵ㣺";
	cin >> index;
	cin >> data;
    item= data;
	if (sl->GetData(index, item) == 0)
		cout <<"SUCCESS" << endl;
	for (int j = 1; j < 3; j++)
	{
		cout << "������Ҫɾ���ĵ�" << j << "��λ�õ���!" << " ";
		cin >> data;
	    item = data;
		cout << "�����������λ��!" << " ";
		cin >> index;
		sl->DeleteElemAtIndex(index, item);
		sl->TravalLinkList();
		num = sl->GetLength();
		cout << endl;
		cout << "�ɹ�ִ�У�������Ϊ:" << num << endl;
	}
	return 0;
}


//����������
void LinkList::TravalLinkList()
{

	Node* p = head->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;

	}
}
//��ȡ������ĳ���
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

//���ҽ��data
int  LinkList::LocateData(const DataType& data) const
{
	Node* p = head->next;
	int count = 1;
	while (p != NULL)
	{
		if (data == p->data) {
			return count;
			break;     //�ҵ�
		}	
		else
		{
			p = p->next;               //ָ���ƶ���������һ��
			count++;
		}
		if (p != NULL)return count;    //�ҵ��������ҵ���λ��
		else return -1;
	}


}
//���ҵ�i�����
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
//��ָ��λ�ò���ָ��Ԫ��
Status LinkList::InsertElemAtIndex(int i, const DataType& data)
{
	Node* p = head;
	int index = 1;
	if (i < 0 || i> length + 1) { //�жϲ���λ��
		cout << "�����λ�ô���" << endl;
		return FAIL;
	}
	else
	{
		while (index < i - 1)       //ָ���ƶ��������ǰһ���ڵ�
		{
			p = p->next;
			index++;
		}
		Node* newp = new Node;  //�µĽڵ�
		newp->next = p->next;   //�µĽڵ�ָ�����λ��Ԫ��
		newp->data = data;      //Ҫ��������ݸ�ֵ���½ڵ��data
		p->next = newp;         //����λ�õ�ǰһ���ڵ��nextָ���½ڵ�
		length++;
		return SUCCESS;
	}
	return FAIL;
}

//ɾ��ָ��������
Status LinkList::DeleteElemAtIndex(int i, DataType& data)
{
	Node* p = head;
	if (i<1 || i>length) return FAIL;            //ɾ��λ�ó�����Χ
	int index = 1;  //ָ��λ��
	while (index <= i - 1)                         //ָ���ƶ���ָ���ڵ��ǰһ���ڵ�
	{
		p = p->next;
		index++;
	}
	Node* rmp = p->next;                       //Ҫɾ���Ľڵ���rmp����
	if (rmp->data == data && rmp->next != NULL) //ɾ����������ȷ��ɾ���ڵ��next��Ϊ��
	{
		p->next = rmp->next;                   //Ҫɾ���ڵ��ǰһ���ڵ�ָ��ɾ���ڵ��next
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


