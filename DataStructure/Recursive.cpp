#include<iostream>
using namespace std;
#define DataType int;
int fact(int n);//�ݹ�ת��Ϊ�ǵݹ�


//int fact(int n) {//�ݹ� ��10�Ľ׳�
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
	void overflow() {//ջ���ʱ����ջ���� 
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
	void push(const T& x) {//��ջ 
		if (isFull())
			overflow();
		element[++top] = x;

	}
	bool pop(T& x) {//��ջ 
		if (isEmpty())
			return false;
		x = element[top--];
		return true;

	}
	bool getTop(T& x) {//��ȡջ��Ԫ�� 
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
	void makeEmpty() {//��ջ�� 
		top = -1;

	}
	void display() {//��ʾջ������Ԫ��
		if (top == -1)
			cout << "ջ�����κ�Ԫ��~!" << endl;
		int leng = getSize();//��ȡջ�ĳ���
		cout << "ջ������Ԫ��Ϊ" << endl;
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
	while (!S->isEmpty())//ȡ�������ۼ����
	{
		S->pop(temp);
		result *= temp;
	}
	return (result);
}