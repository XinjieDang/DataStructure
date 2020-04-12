#include<iostream>
using namespace std;//��ʽ���е�ʵ��
template < class T>
struct LinkNode {//����ڵ� 
	T data;        //����������
	LinkNode* link;//����ָ����
};
template < class T>
class LinkedQueue {//��ʽ����
	LinkNode<T>* front;   //��ͷ
	LinkNode<T>* rear;    //��β
public:
	LinkedQueue() {//��ʼ��������һ���ն���
		front = new LinkNode<T>;
		front->link = NULL;
		rear = front;
	}
	~LinkedQueue() {
		makeEmpty();
	}
	void push(const T& x) {//ֵΪx ��Ԫ���ڶ�β���
		 //rear = new LinkNode<T>(x, rear);
		 LinkNode<T>* newp = new LinkNode<T>;//�´������
		 if (!newp) exit(OVERFLOW);
		 newp->data = x;
		 newp->link = NULL;      //�½���ָ�����ÿ�
		 rear->link = newp;      //ԭ�����е�β���ָ���½��
		 rear = newp;            //��βָ��ָ���½��
	}
	bool pop(T& x) {//ֵΪx ��Ԫ���ڶ�ͷ����
		if (isEmpty()) return false;
		LinkNode<T>* delp;
		delp = front->link;            //��ͷfrontָ��ָ��ͷ���.��Ҫ���ӵĽ����� front->link
		x = delp->data;                //Ҫ���ӵ�Ԫ�ظ�ֵ��x
		front->link = delp->link;      //ָ��ͷ����ָ��ָ��delp����һ�����
		if (rear == delp) rear = front;//���ԭ����ֻ��һ��Ԫ�أ�ɾ����rearָ�뻹ԭ��frontָ��
		delete delp;

	}
	bool getfront(T& x)const {//���ضӶ�Ԫ�� 
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
	void makeEmpty() {//���ÿ� 
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
	void display() {//��ʾ����������Ԫ��
		if (isEmpty()) {
			cout << "�ն���!" << endl;
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
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	cout << "3.��ȡ�Ӷ�Ԫ��" << endl;
	cout << "4.���ÿ�" << endl;
	cout << "5.��ʾ��������Ԫ��" << endl;
	cout << "6.�˳�" << endl;

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