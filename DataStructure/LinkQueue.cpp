#include<iostream>
using namespace std;//链式队列的实现
template < class T>
struct LinkNode {//链表节点 
	T data;        //链表数据域
	LinkNode* link;//链表指针域
};
template < class T>
class LinkedQueue {//链式队列
	LinkNode<T>* front;   //队头
	LinkNode<T>* rear;    //队尾
public:
	LinkedQueue() {//初始化，构建一个空队列
		front = new LinkNode<T>;
		front->link = NULL;
		rear = front;
	}
	~LinkedQueue() {
		makeEmpty();
	}
	void push(const T& x) {//值为x 的元素在队尾入队
		 //rear = new LinkNode<T>(x, rear);
		 LinkNode<T>* newp = new LinkNode<T>;//新创建结点
		 if (!newp) exit(OVERFLOW);
		 newp->data = x;
		 newp->link = NULL;      //新结点的指针域置空
		 rear->link = newp;      //原来队列的尾结点指向新结点
		 rear = newp;            //队尾指针指向新结点
	}
	bool pop(T& x) {//值为x 的元素在队头出队
		if (isEmpty()) return false;
		LinkNode<T>* delp;
		delp = front->link;            //队头front指针指向头结点.故要出队的结点等于 front->link
		x = delp->data;                //要出队的元素赋值给x
		front->link = delp->link;      //指向头结点的指针指向delp的下一个结点
		if (rear == delp) rear = front;//如果原队列只有一个元素，删除后将rear指针还原到front指针
		delete delp;

	}
	bool getfront(T& x)const {//返回队顶元素 
		if (isEmpty())
			return false;
		x = front->data;
		return true;

	}
	bool isEmpty()const {
		return (rear == front) ? true : false;

	}
	int getSize()const {
		LinkNode<T>* p = front;
		int k = 0;
		while (p != NULL) {
			p = p->link;
			k++;

		}
		return k;
	}
	void makeEmpty() {//队置空 
		LinkNode<T>* p;
		p = front->link;
		while (p)
		{
			rear = p->link;
			delete p;
			p =rear;
		}
		rear = front;
		front->link = NULL;

	}
	void display() {//显示队列里所有元素
		if (isEmpty()) {
			cout << "空队列!" << endl;
		}
		else {
			LinkNode<T>* p = front->link;
			while (p)
			{
				cout << p->data << " ";
				p = p->link;
			}
			cout << endl;
		}
	}
};

void menu() {
	cout << "1.进队" << endl;
	cout << "2.出队" << endl;
	cout << "3.获取队顶元素" << endl;
	cout << "4.队置空" << endl;
	cout << "5.显示队列所有元素" << endl;
	cout << "6.退出" << endl;

}
template < class T>
void function(int num, LinkedQueue<T>* ls) {
	switch (num) {
		int x;
	case 1:
		cin >> x;
		ls->push(x);
		break;
	case 2:
		ls->pop(x);
		break;
	case 3:
		ls->getfront(x);
		cout << x << endl;
		break;
	case 4:
		ls->makeEmpty();
		break;
	case 5:
		ls->display();
		break;
	case 6:
		exit(1);
		break;

	}

}
int main(int argc, char** argv) {
	LinkedQueue<int>* ls = new LinkedQueue<int>;
	int num;
	while (true) {
		menu();
		cin >> num;
		function(num, ls);

	}
	delete ls;
	return 0;

}