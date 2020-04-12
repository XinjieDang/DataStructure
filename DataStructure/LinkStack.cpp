#include<iostream>
using namespace std;//��ʽջ
template < class T>
struct LinkNode {//����ڵ� 
	T data;        //����������
	LinkNode* link;//����ָ����
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
	void push(const T& x) {//��ջ 
		top = new LinkNode<T>(x, top);

	}
	bool pop(T& x) {//��ջ 
		if (isEmpty())
			return false;
		LinkNode<T>* p = top;
		top = top->link;
		x = p->data;
		delete p;

	}
	bool getTop(T& x)const {//����ջ��Ԫ�� 
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
	void makeEmpty() {//ջ�ÿ� 
		LinkNode<T>* p;
		while (top != NULL) {
			p = top;
			top = top->link;
			delete p;
		}
	}
	void display() {//��ʾջ������Ԫ��
		if (!isEmpty()) {
			LinkNode<T>* p;           //����һ������ָ��p
			p = top;                  //��p ��Ϊջ���ڵ�
			while (p) {
				cout << p->data << " ";
				p = p->link;          // P�ĺ�̸�ֵ��P
			}
			cout << endl;
		}
		else
			cout << "ջ�����κ�Ԫ��!"<<endl;
	}
};

void menu() {
	cout << "1.��ջ" << endl;
	cout << "2.��ջ" << endl;
	cout << "3.��ȡջ��Ԫ��" << endl;
	cout << "4.ջ�ÿ�" << endl;
	cout << "5.��ʾ����Ԫ��" << endl;
	cout << "6.�˳�" << endl;

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