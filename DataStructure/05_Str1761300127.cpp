#include <iostream>
#include <conio.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;
class String
{
public:
    String() {};
    ~String() {};
    String SubString(int pos, int num);
    void Insert(String t, int pos);
    void Delete(int pos, int num);
    void Creat();
    void Display();
private:
    char* str;
    int size;
};
//�������ַ�������
void String::Creat()
{
    char* s = new char(100);
    cin >> s;
    size = strlen(s);
    str = new char[size];
    if (str == 0)  cout << "û�����뵽�ռ䣡";
    strcpy(str, s);
}
//���
void String::Display()
{
    int i;
    for (i = 0; i < size; i++)  cout << str[i];
    cout << endl;
}
//���Ӵ�
String String::SubString(int pos, int num)
{
    //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
    String strs;
    if (pos >= 0 && pos < size)//�жϽ�ȡλ��
    {
        strs.str = new char[num + 1];// ������ʱ�ռ�
        for (int i = 0; i < num; i++)// ��ȡstr 0-n�е��ַ�
        {
            strs.str[i] = str[pos + i - 1];
        }
        strs.str[num] = '\0';
        strs.size = num;//���� str ��С
        return strs;
    }
    else
    {
        strs.size = -1;
        return strs;
    }

}
//��������:�ڴ�����s��posλ�ú����һ����t
void String::Insert(String t, int pos)
{
    //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
    if (pos<0 || pos>size)
    {
        cout << "����λ�ô���";
    }
    String strs;
    strs.size = size + t.size;
    strs.str = new char[strs.size + 1];
    for (int i = 0; i <= pos - 1; i++)
    {
        strs.str[i] = str[i];
    }
    for (int j = 0; j <=t.size; j++)
    {
        strs.str[j+pos] = t.str[j];
    }
    for (int k = pos; k<= size; k++)
    {
        strs.str[k+ t.size] = str[k];
        str = strs.str;
        size = strs.size;
    }

}
//ɾ�� :ɾ�����е�һ���Ӵ�
void  String::Delete(int pos, int num)
{
    //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
    if (pos<0 || pos>size)
    {
        cout << "�����λ�÷Ƿ�";
        return;
    }
    else
    {
        String cs;
        cs.size = size - num;
        cs.str = new char[cs.size + 1];
        for (int i = 0; i <= pos - 1; i++)
        {
            cs.str[i] = str[i];
        }
        for (int k = pos; k <= size - num; k++)
        {
            cs.str[k] = str[k + num];
        }
        str = cs.str;
        size = cs.size;
    }

   
}
//������
int main(int argc, char* argv[])
{
    int pos, num, k;
    String s, s1, t;
    do {
        cout << "\n\n    1.�����ַ���";
        cout << "\n\n    2.ȡ�Ӵ�";
        cout << "\n\n    3.�����Ӵ�s1";
        cout << "\n\n    4.ɾ���Ӵ�";
        cout << "\n\n    5.��������";
        cout << "\n******************************** ";
        cout << "\n    ���������ѡ��(1,2,3,4,5)";  cin >> k;
        switch (k) {
        case 1: {cout << "������һ���ַ�����";
            s.Creat();
            cout << "�ַ���Ϊ��       ";     s.Display();
        }break;
        case 2: { cout << "�������Ӵ��Ľ�ȡλ��pos���Ӵ�����num" << endl;
            cin >> pos >> num;
            t = s.SubString(pos, num);
            cout << "����ȡ���Ӵ�Ϊ������";  t.Display();
        }break;
        case 3: { cout << "�������Ӵ�����λ��pos" << endl;
            cin >> pos;
            cout << "������Ҫ������Ӵ�:  ";   s1.Creat();
            s.Insert(s1, pos);
            cout << "�������ַ���Ϊ��   ";  s.Display();
        }break;
        case 4: { cout << "������Ҫɾ���Ӵ��Ŀ�ʼλ��pos���Ӵ�����num" << endl;
            cin >> pos >> num;
            s.Delete(pos, num);
            cout << "ɾ������ַ���Ϊ��   ";
            s.Display();
        }break;
        default:break;
        } //switch
        cout << "\n--------------------------------- ";
    } while (k >= 1 && k < 5);
    cout << "\n          �ټ�!";
    cout << "\n     ������������ء�";
    return 0;
}
