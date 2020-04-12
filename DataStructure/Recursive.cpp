#include<iostream>
using namespace std;
#define DataType int;
int fact(int n);//递归转化为非递归


//int fact(int n) {//递归 求10的阶乘
//	long f;
//	if (n < 0)
//		f = -1;
//	else if (n == 1 || n == 0)
//		f = 1;
//	else
//		f = n * fact(n - 1);
//	return f;
//}
int main() {
	cout << fact(10) << endl;
	system("pause");
	return 0;
}
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
		int leng = getSize();//获取栈的长度
		cout << "栈中所有元素为" << endl;
		for (int i = 0; i < leng; i++) {
			cout << element[i] << ",";
		}
		cout << endl;
	}
};
int fact(int n) {
	int result, temp;
	SeqStack<int>* S = new SeqStack<int>;
	while (n>0)
	{
		S->push(n);
		n--;
	}
	result = 1;
	while (!S->isEmpty())//取出来，累加求和
	{
		S->pop(temp);
		result *= temp;
	}
	return (result);
}