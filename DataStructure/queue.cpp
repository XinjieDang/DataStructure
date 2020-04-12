#include <iostream>
using namespace std;
typedef int DataType;
const int MaxSize = 20;
class SeqQueue
{//˳�����
	
private:
	DataType data[MaxSize];
	int maxSize;
	int rear;
	int front;
public:
	SeqQueue();
	~SeqQueue();
	int EnQueue(DataType d);
	int DeQueue(DataType& e);
	int Front(DataType& e);  //ȡ����Ԫ��
	bool IsEmpty();//�����п�
	void display();//��ʾ��������Ԫ��
};
SeqQueue::SeqQueue()
{
	maxSize = MaxSize;
	rear = 0;
	front = 0;
}
SeqQueue::~SeqQueue()
{
	delete data;
}

int SeqQueue::EnQueue(DataType d)
{
	if ((rear + 1) % maxSize != front) //�Ӳ����������
	{
		data[rear] = d;
		rear = (rear + 1) % maxSize;//�������ö�βָ��
		return 1;
	}
	else
	{
		cout << "��������" << endl;
		return 0;
	}

}
int SeqQueue::DeQueue(DataType& d)
{
	if (rear != front) //�Ӳ��ղ��ܳ���
	{
		d = data[front];
		front = (front + 1) % maxSize;//�������ö�ͷָ��
		return 1;
	}
	else
	{
		cout << "�ն���" << endl;
		return 0;
	}
}
bool SeqQueue::IsEmpty()
{
	return (rear == front) ? true : false;

}
int SeqQueue::Front(DataType& e)
{
	if (rear != front) //�Ӳ��ղ��ܳ���
	{
		e = data[front];
		return 1;
	}
	else
	{
		cout << "�ն���" << endl;
		return 0;
	}
}

/*
ѭ�������ڶӿպͶ���ʱ�����Ƕ�ͷָ��Ͷ�βָ��ָ��ͬһ��λ�ã�
���֣�����һ���洢�ռ䣬�ӿ� ���ж��������䣬��βָ��real��1���ڶ�ͷָ��Ϊ���е���������
����front = rear ��ʾ�ӿգ���rear + 1) % MaxSize == fornt ��ʾ������
*/
void SeqQueue::display()
{
	if (!IsEmpty())//��ͷ����β��������������δ��
	{
		int i = front;
		if (front < rear)
		{
			for (; i < rear; i++)
			{
				cout << data[i] << " " ;
			}
		}
		else
		{
			for (; i < rear + maxSize; i++)
			{
				cout << data[i] << " " ;
			}
		}
	/*	while (rear != i)//ֱ�ӱ�����������
		{
			cout << data[i] << " ";
			i = (i + 1) % maxSize;
		}*/
		cout << endl;
	}
	else
		cout << "�ն��У���Ԫ�أ�" << endl;
}
void menu() {
	cout << "1.���" << endl;
	cout << "2.����" << endl;
	cout << "3.ȡ����Ԫ��" << endl;
	cout << "4.��ʾ����Ԫ��" << endl;
	cout << "5.�˳�" << endl;

}
void function(int num, SeqQueue* seq) {
	switch (num) {
		int x;
	case 1:
		cin >> x;
		seq->EnQueue(x);
		break;
	case 2:
		seq->DeQueue(x);
		break;
	case 3:
		seq->Front(x);
		cout << x << endl;
		break;
	case 4:
		seq->display();
		break;
	case 5:
		exit(1);
		break;

	}
}
int main(int argc, char** argv) {
	SeqQueue* sq = new SeqQueue();
	int num;
	while (true) {
		menu();
		cin >> num;
		function(num, sq);
	}
	delete sq;
	return 0;

}