#include<iostream>
using namespace std;
/*使用双栈实现队列，栈是先进后出，一个栈s1进栈(队尾），一个栈s2出栈(队头)
s1 全部元素移到s2,从s2出栈
*/
template < class T>
class Stack {
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
	void push(int x)//添加元素到队尾
	{
		s1.push(x);
	}
	int pop()     //删除队头元素并返回
	{	
		// 先调用 peek 保证 s2 非空
		peek();
		return s2.pop();

	}

	int peek()      // 返回队头元素
	{
		if (s2.isEmpty())
			// 把 s1 元素压入 s2
			while (!s1.isEmpty())
				s2.push(s1.pop());
		return s2.peek();

	}
	bool empty()  //判断队列是否为空
	{
		return s1.isEmpty() && s2.isEmpty();
	}
};

