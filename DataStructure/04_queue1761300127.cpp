#include<iostream>
#include<conio.h>
using namespace std;
//#define MAXSIZE 3
const int MaxSize = 20;
typedef int ElemType;
class SeQueue
{
private:
    ElemType elem[MaxSize];
    int front;
    int rear;
    int maxSize;
public:
    SeQueue();
    ~SeQueue();
    void Display();
    void AddQ(ElemType x);
    ElemType DelQ();
};
SeQueue::SeQueue()
{
    maxSize = MaxSize;
    front = 0;
    rear = 0;
    cout << "init!" << endl;
}
SeQueue::~SeQueue()
{
    delete elem;

};//{ delete [MAXSIZE]Q.elem;}
void SeQueue::Display()
{
   /* ElemType x; 
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
            j = (j + 1) % maxSize;
        }
    }
    cout << endl;*/

    if (rear != front)//��ͷ����β��������������δ��
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
            for (; i < rear + maxSize; i++)
            {
                cout << elem[i] << " ";
            }
        }
        cout << endl;
    }
    else
        cout << "�ն��У���Ԫ�أ�" << endl;
}
void SeQueue::AddQ(ElemType x)
{  //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
    if ((rear + 1) % maxSize != front) //�Ӳ����������
    {
        elem[rear] = x;
        rear = (rear + 1) % maxSize;//�������ö�βָ��
        cout << "SUCCESS"<<endl;
    }
    else
    {
        cout << "��������" << endl;
  
    }
}
ElemType SeQueue::DelQ()
{
    //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
    ElemType d;
    if (rear != front) //�Ӳ��ղ��ܳ���
    {
        d = elem[front];
        front = (front + 1) % maxSize;//�������ö�ͷָ��
        return d;
    }
    else
    {
        cout << "�ն���" << endl;
        
    }

}
int main()
{
    ElemType e;  
    int j;
    SeQueue h;
    int k;
    cout << "\n                           ���д洢�ṹ��ʾ";
    do {
        cout << "\n\n";
        cout << "\n\n    1.��������һ������";
        cout << "\n\n    2.�����������";
        cout << "\n\n    3.���";
        cout << "\n\n    4.����";
        cout << "\n\n    5.��������";
        cout << "\n******************************** ";
        cout << "\n    ���������ѡ��(1,2,3,4,5)";
        cin >> k;
        switch (k) {
        case 1: {
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
        default:break;
        }
        cout << "\n--------------------------------- ";
    } while (k >= 1 && k < 5);
    cout << "\n          �ټ�!";
    cout << "\n     ������������ء�";
    _getch(); return 0;
}