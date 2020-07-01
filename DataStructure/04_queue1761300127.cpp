#include <iostream>
#include <conio.h>
#define MAXSIZE 4
using namespace std;
typedef int ElemType;
class SeQueue
{
private:
    ElemType elem[MAXSIZE];
    int front, rear;
public:
    SeQueue();
    ~SeQueue();
    void Display();
    void AddQ(ElemType x);
    ElemType DelQ();
    long Fib(int n);
    long Fib_loop(int n);
};
SeQueue::SeQueue()
{
    front = 0;
    rear = 0;
    cout << "init!" << endl;
}
SeQueue::~SeQueue()
{};//{ delete [MAXSIZE]Q.elem;}
void SeQueue::Display()
{

   

    for (int i = front; i != rear; i = (i + 1) % MAXSIZE)
        cout << elem[i] << " ";



}
void SeQueue::AddQ(ElemType x)
{  //将此成员函数补充完整，使得程序能够正确运行
    if ((rear + 1) % MAXSIZE != front) //队不满才能入队
    {
        elem[rear] = x;
        rear = (rear + 1) % MAXSIZE;//重新设置队尾指针
        cout << "SUCCESS" << endl;
    }
    else
    {
        cout << "队列已满" << endl;

    }
}
ElemType SeQueue::DelQ()
{
    //将此成员函数补充完整，使得程序能够正确运行
    ElemType x;
    if (rear != front) //队不空才能出队
    {
        x= elem[front];
        front = (front + 1) % MAXSIZE;//重新设置队头指针
        return x;
    }
    else
    {
        cout << "空队列" << endl;

    }
}

long SeQueue::Fib(int n)//递归实现斐波那契数列
{
    long result = 0;
    if (n == 0 || n == 1)
        return n;
    else//当 n>=2;
    {
        result= Fib(n - 1) + Fib(n - 2);
        return result;
           
         
    }

}
long SeQueue::Fib_loop(int n)//非递归（循环）实现斐波那契数列
{
    long twoback = 0, oneback = 1, current;
    if (n == 0 || n == 1)
        return n;
    for (int i = 2; i <= n; i++)//当 n>=2
    {
        current = twoback + oneback;
        twoback = oneback;
        oneback = current;

    }
    return current;
}
int main()
{
    ElemType e; 
    int j;
    SeQueue h;
    int k, num;
    cout << "\n                           队列存储结构演示";
    do {
        cout << "\n\n";
        cout << "\n\n    1.初步建立一个队列";
        cout << "\n\n    2.输出整个队列";
        cout << "\n\n    3.入队";
        cout << "\n\n    4.出队";
        cout << "\n\n    5.斐波那契数列（递归)";
        cout << "\n\n    6.斐波那契数列（非递归)";
        cout << "\n\n    7.结束程序";
        cout << "\n******************************** ";
        cout << "\n    请输入你的选择(1,2,3,4,5)";
        cin >> k;
        switch (k) {
        case 1: {SeQueue::SeQueue();
        }break;
        case 2: {h.Display();
        }break;
        case 3: {
            cout << "进队  data=?";  cin >> e;
            h.AddQ(e);
            h.Display();
        }break;
        case 4: {   e = h.DelQ();
            if (e != -1)
                cout << "出队的结点值是：" << e << endl;
            h.Display();
        }break;

        case 5: {

            cout << "斐波那契数列（递归），请输入一个数：" << endl;
            cin >> num;
            cout << "结果为: " << h.Fib(num);

        }break;
        case 6: {
            cout << "斐波那契数列（非递归），请输入一个数：" << endl;
            cin >> num;
            cout << "结果为: " << h.Fib_loop(num);
        }break;



        default:break;
        }
        cout << "\n--------------------------------- ";
    } while (k >= 1 && k < 8);
    cout << "\n          再见!";
    cout << "\n     按任意键，返回。";
    _getch(); return 0;
}
