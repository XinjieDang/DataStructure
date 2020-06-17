#include <iostream>
#include <conio.h>
#define MAXSIZE 20
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
    /*ElemType x;
    int j = 0;
    if (rear == front)
    {
        cout << "QUEUE IS FULL!";
    }
    else {
        j = front + 1; 
        while (j != rear + 1)
        {
            x = elem[j]; 
            cout << x << " "; 
            j = (j + 1) % MAXSIZE;
        }
    }
    cout << endl;*/

    if (rear != front)//从头到队尾，包括队满，队未满
    {
        int i = front;
        if (front < rear)
        {
            for (; i < rear; i++)
            {
                cout << elem[i] << " ";
            }
        }
        else
        {
            for (; i < rear + MAXSIZE; i++)
            {
                cout << elem[i] << " ";
            }
        }
        cout << endl;
    }
    else
        cout << "空队列，无元素！" << endl;



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
    ElemType d;
    if (rear != front) //队不空才能出队
    {
        d = elem[front];
        front = (front + 1) % MAXSIZE;//重新设置队头指针
        return d;
    }
    else
    {
        cout << "空队列" << endl;

    }
}
int main()
{
    ElemType e;  int j;
    SeQueue h;
    int k;
    cout << "\n                           队列存储结构演示";
    do {
        cout << "\n\n";
        cout << "\n\n    1.初步建立一个队列";
        cout << "\n\n    2.输出整个队列";
        cout << "\n\n    3.入队";
        cout << "\n\n    4.出队";
        cout << "\n\n    5.结束程序";
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
        default:break;
        }
        cout << "\n--------------------------------- ";
    } while (k >= 1 && k < 5);
    cout << "\n          再见!";
    cout << "\n     按任意键，返回。";
    _getch(); return 0;
}
