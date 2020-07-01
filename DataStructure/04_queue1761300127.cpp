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
{  //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
    if ((rear + 1) % MAXSIZE != front) //�Ӳ����������
    {
        elem[rear] = x;
        rear = (rear + 1) % MAXSIZE;//�������ö�βָ��
        cout << "SUCCESS" << endl;
    }
    else
    {
        cout << "��������" << endl;

    }
}
ElemType SeQueue::DelQ()
{
    //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
    ElemType x;
    if (rear != front) //�Ӳ��ղ��ܳ���
    {
        x= elem[front];
        front = (front + 1) % MAXSIZE;//�������ö�ͷָ��
        return x;
    }
    else
    {
        cout << "�ն���" << endl;

    }
}

long SeQueue::Fib(int n)//�ݹ�ʵ��쳲���������
{
    long result = 0;
    if (n == 0 || n == 1)
        return n;
    else//�� n>=2;
    {
        result= Fib(n - 1) + Fib(n - 2);
        return result;
           
         
    }

}
long SeQueue::Fib_loop(int n)//�ǵݹ飨ѭ����ʵ��쳲���������
{
    long twoback = 0, oneback = 1, current;
    if (n == 0 || n == 1)
        return n;
    for (int i = 2; i <= n; i++)//�� n>=2
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
    cout << "\n                           ���д洢�ṹ��ʾ";
    do {
        cout << "\n\n";
        cout << "\n\n    1.��������һ������";
        cout << "\n\n    2.�����������";
        cout << "\n\n    3.���";
        cout << "\n\n    4.����";
        cout << "\n\n    5.쳲��������У��ݹ�)";
        cout << "\n\n    6.쳲��������У��ǵݹ�)";
        cout << "\n\n    7.��������";
        cout << "\n******************************** ";
        cout << "\n    ���������ѡ��(1,2,3,4,5)";
        cin >> k;
        switch (k) {
        case 1: {SeQueue::SeQueue();
        }break;
        case 2: {h.Display();
        }break;
        case 3: {
            cout << "����  data=?";  cin >> e;
            h.AddQ(e);
            h.Display();
        }break;
        case 4: {   e = h.DelQ();
            if (e != -1)
                cout << "���ӵĽ��ֵ�ǣ�" << e << endl;
            h.Display();
        }break;

        case 5: {

            cout << "쳲��������У��ݹ飩��������һ������" << endl;
            cin >> num;
            cout << "���Ϊ: " << h.Fib(num);

        }break;
        case 6: {
            cout << "쳲��������У��ǵݹ飩��������һ������" << endl;
            cin >> num;
            cout << "���Ϊ: " << h.Fib_loop(num);
        }break;



        default:break;
        }
        cout << "\n--------------------------------- ";
    } while (k >= 1 && k < 8);
    cout << "\n          �ټ�!";
    cout << "\n     ������������ء�";
    _getch(); return 0;
}
