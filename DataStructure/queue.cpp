#include <iostream>
using namespace std;
typedef int DataType;
const int MaxSize = 20;
class SeqQueue
{//顺序队列
	
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
	int Front(DataType& e);  //取队首元素
	bool IsEmpty();//队列判空
	void display();//显示队列所有元素
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
	if ((rear + 1) % maxSize != front) //队不满才能入队
	{
		data[rear] = d;
		rear = (rear + 1) % maxSize;//重新设置队尾指针
		return 1;
	}
	else
	{
		cout << "队列已满" << endl;
		return 0;
	}

}
int SeqQueue::DeQueue(DataType& d)
{
	if (rear != front) //队不空才能出队
	{
		d = data[front];
		front = (front + 1) % maxSize;//重新设置队头指针
		return 1;
	}
	else
	{
		cout << "空队列" << endl;
		return 0;
	}
}
bool SeqQueue::IsEmpty()
{
	return (rear == front) ? true : false;

}
int SeqQueue::Front(DataType& e)
{
	if (rear != front) //队不空才能出队
	{
		e = data[front];
		return 1;
	}
	else
	{
		cout << "空队列" << endl;
		return 0;
	}
}

/*
循环队列在队空和队满时，都是队头指针和队尾指针指向同一个位置：
区分：少用一个存储空间，队空 的判断条件不变，以尾指针real加1等于队头指针为队列的判满条件
即：front = rear 表示队空，（rear + 1) % MaxSize == fornt 表示队满。
*/
void SeqQueue::display()
{
	if (!IsEmpty())//从头到队尾，包括队满，队未满
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
	/*	while (rear != i)//直接遍历包括队满
		{
			cout << data[i] << " ";
			i = (i + 1) % maxSize;
		}*/
		cout << endl;
	}
	else
		cout << "空队列，无元素！" << endl;
}
void menu() {
	cout << "1.入队" << endl;
	cout << "2.出队" << endl;
	cout << "3.取队首元素" << endl;
	cout << "4.显示所有元素" << endl;
	cout << "5.退出" << endl;

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