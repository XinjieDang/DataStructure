#include<iostream>
using namespace std;
/*ʹ��˫ջʵ�ֶ��У�ջ���Ƚ������һ��ջs1��ջ(��β����һ��ջs2��ջ(��ͷ)
s1 ȫ��Ԫ���Ƶ�s2,��s2��ջ
*/
template < class T>
class Stack {
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
};
template < class T>
class Queue {
private:
	private Stack<T> s1, s2;
public:
	Queue()
	{
		s1 = new Stack<>();
		s2 = new Stack<>();


	}
	void push(int x)//���Ԫ�ص���β
	{
		s1.push(x);
	}
	int pop()     //ɾ����ͷԪ�ز�����
	{	
		// �ȵ��� peek ��֤ s2 �ǿ�
		peek();
		return s2.pop();

	}

	int peek()      // ���ض�ͷԪ��
	{
		if (s2.isEmpty())
			// �� s1 Ԫ��ѹ�� s2
			while (!s1.isEmpty())
				s2.push(s1.pop());
		return s2.peek();

	}
	bool empty()  //�ж϶����Ƿ�Ϊ��
	{
		return s1.isEmpty() && s2.isEmpty();
	}
};

