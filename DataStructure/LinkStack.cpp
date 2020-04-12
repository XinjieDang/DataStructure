#include<iostream>
using namespace std;//链式栈
template < class T>
struct LinkNode {//链表节点 
	T data;        //链表数据域
	LinkNode* link;//链表指针域
	LinkNode(const T& args, LinkNode<T>* ptr = NULL) {
		data = args;
		link = ptr;
	}
};
template < class T>
class LinkedStack {
	LinkNode<T>* top;
public:
	LinkedStack() {
		top = NULL;


	}
	~LinkedStack() {
		makeEmpty();

	}
	void push(const T& x) {//进栈 
		top = new LinkNode<T>(x, top);

	}
	bool pop(T& x) {//出栈 
		if (isEmpty())
			return false;
		LinkNode<T>* p = top;
		top = top->link;
		x = p->data;
		delete p;

	}
	bool getTop(T& x)const {//返回栈顶元素 
		if (isEmpty())
			return false;
		x = top->data;
		return true;

	}
	bool isEmpty()const {
		return (top == NULL) ? true : false;

	}
	int getSize()const {
		LinkNode<T>* p = top;
		int k = 0;
		while (p != NULL) {
			p = p->link;
			k++;

		}
		return k;

	}
	void makeEmpty() {//栈置空 
		LinkNode<T>* p;
		while (top != NULL) {
			p = top;
			top = top->link;
			delete p;
		}
	}
	void display() {//显示栈里所有元素
		if (!isEmpty()) {
			LinkNode<T>* p;           //定义一个工作指针p
			p = top;                  //让p 成为栈顶节点
			while (p) {
				cout << p->data << " ";
				p = p->link;          // P的后继赋值给P
			}
			cout << endl;
		}
		else
			cout << "栈中无任何元素!"<<endl;
	}
};

void menu() {
	cout << "1.进栈" << endl;
	cout << "2.出栈" << endl;
	cout << "3.获取栈顶元素" << endl;
	cout << "4.栈置空" << endl;
	cout << "5.显示所有元素" << endl;
	cout << "6.退出" << endl;

}
template < class T>
void function(int num, LinkedStack<T>* ls) {
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
		ls->getTop(x);
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
	LinkedStack<int>* ls = new LinkedStack<int>;
	int num;
	while (true) {
		menu();
		cin >> num;
		function(num, ls);
	}
	delete ls;
	return 0;

}