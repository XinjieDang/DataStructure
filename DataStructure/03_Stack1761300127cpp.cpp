
//ջ��˳��洢�ṹ��˳�����
#include<iostream>
#include<conio.h>
#include <iomanip>
using namespace std;
//------------------------------ջ��˳��洢�ṹ---------------------------------------------
typedef int  ElemType;     // ����Ԫ�ص�����
const int MAXSIZE = 50;     // ���������
class SqStack
{
private:
    ElemType  elem[MAXSIZE];
    int top;
public:
    SqStack(void);
    ~SqStack() {};
    int  SetEmpty();
    void  push(const ElemType e);
    ElemType pop();
    void PrintOut();
    int IsEmpty(void)const;
};
//-------------------------------------------------------------
SqStack::SqStack(void) :top(0) { }
int  SqStack::SetEmpty()
{
    return top == 0;
}
void  SqStack::push( const ElemType e)
{
    //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
    if (top == MAXSIZE)//˳��ջ����
        cout << "˳��ջ����!";
    else
    {
        elem[++top] = e;//��Ԫ��e׷�ӵ�ջ������top��һ
        cout << "SUCCESS" << endl;

    }

}
ElemType SqStack::pop()
{
    //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
    ElemType e;
    if (IsEmpty() == 1)
        cout << "��ǰ�ǿ�ջ!";
    else
    {
        e = elem[top--];//��e ����ջ��Ԫ�أ���ջ��ָ���һ
        cout << "SUCCESS" << endl;
        return e;
    }
}
void SqStack::PrintOut()
{
    int k;
    cout << "\n PrintOut Data:\n";
    for (k = top; k >= 1; k--) cout << setw(6) << elem[k];
    cout << endl;
}
int SqStack::IsEmpty(void)const
{
    if (top == 0) return 1;
    else return 0;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int i, k;
    ElemType e, x;
    SqStack  as;
    cout << "\n                           ջ��˳��洢�ṹʵ��";
    do {
        cout << "\n\n";
        cout << "\n\n    1.����һ������Ԫ��e����ջ��";
        cout << "\n\n    2.ɾ��һ��Ԫ�أ�������ֵ����ջ��";
        cout << "\n\n    3..��������";
        cout << "\n******************************** ";
        cout << "\n    ���������ѡ��(1,2,3,4,5,6)";    cin >> k;
        switch (k) {
        case 1: {cout << "\n ��ջ������ e=?";
            cin >> e;
            as.push(e);
            as.PrintOut();
        }break;
        case 2: {  cout << "\n ��ջ";
            x = as.pop();
            cout << "\n  ��ջԪ����ֵ= " << x<<endl;
            cout << "ջ��ʣ��Ԫ��Ϊ��";
            as.PrintOut();
        }break;
        default:break;
        } //switch
        cout << "\n--------------------------------- ";
    } while (k >= 1 && k < 3);
    cout << "\n          �ټ�!";
    cout << "\n     ������������ء�";
    _getch(); return 0;
}
//-----------------------------------------------
