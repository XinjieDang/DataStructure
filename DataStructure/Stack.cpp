#include<iostream>
using namespace std;
template < class T>
class SeqStack {
	T* element;
	int top;
	int maxSize;
	void overflow() {//栈溢出时扩大栈容量 
		T* newArray = new T[maxSize + 20];
		for (int i = 0; i <= top; i++) {
			newArray[i] = element[i];

		}
		maxSize += 20;
		delete[]element;
		element = newArray;

	}
public:
	SeqStack(int sz = 50) {
		top = -1;
		maxSize = sz;
		element = new T[maxSize];

	}
	~SeqStack() {
		delete[] element;

	}
	void push(const T& x) {//进栈 
		if (isFull())
			overflow();
		element[++top] = x;

	}
	bool pop(T& x) {//出栈 
		if (isEmpty())
			return false;
		x = element[top--];
		return true;

	}
	bool getTop(T& x) {//获取栈顶元素 
		if (isEmpty())
			return false;
		x = element[top];
		return true;

	}
	bool isEmpty()const {
		return (top == -1) ? true : false;

	}
	bool isFull()const {
		return (top == maxSize - 1) ? true : false;

	}
	int getSize() {
		return top + 1;

	}
	void makeEmpty() {//置栈空 
		top = -1;

	}
	void display() {//显示栈里所有元素
		if (top == -1)
			cout << "栈中无任何元素~!" << endl;
		int index = top;
		while (index!=-1)//从栈顶到栈顶
		{
			cout << element[index] << ",";
			index--;
		}
		cout << endl;
	}
};

void menu() {
	cout << "1.进栈" << endl;
	cout << "2.出栈" << endl;
	cout << "3.获取栈顶元素" << endl;
	cout << "4.栈置空" << endl;
	cout << "5.显示栈的元素" << endl;
	cout << "6.退出" << endl;

}
template < class T>
void function(int num, SeqStack<T>* ss) {
	switch (num) {
		int x;
	case 1:
		cin >> x;
		ss->push(x);
		break;
	case 2:
		ss->pop(x);
		break;
	case 3:
		ss->getTop(x);
		cout << x << endl;
		break;
	case 4:
		ss->makeEmpty();
		break;
		break;
	case 5:
		ss->display();
		break;
	default:
		exit(1);

	}

}

int main(int argc, char** argv) {
	SeqStack<int>* ss = new SeqStack<int>;
	int num;
	while (true) {
		menu();
		cin >> num;
		function(num, ss);

	}
	delete ss;
	return 0;

}