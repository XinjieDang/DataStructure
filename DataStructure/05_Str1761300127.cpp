#include<iostream>
using namespace std;
#include <conio.h>
#include <string.h>//c++ ����
class String
{
public:
    String()//��ʼ��һ���մ�
    {
        size = 0;
        str = NULL;
    };
    ~String() 
    {
        delete[] str;
    };
    String SubString(int pos, int num);
    void Insert(String t, int pos);
    void Delete(int pos, int num);
    void Creat();
    void Display();
private:
    char* str;//��ֵ
    int size;//����
};
//�������ַ�������
void String::Creat()
{
    char* s = new char(100);
    cin >> s;
    size = strlen(s); //strlen ������
    str = new char[size];
    if (str == 0)  cout << "û�����뵽�ռ䣡";
    //strcpy����
    //���ǽ� s�ַ����鸴�Ƶ�str�����У����str���鱾�������ݣ�
    //���s�������ȫ�����Ƶ�str�У����str��������С��s��ַ���ȵĽ��ᱻ���ǣ�������s���ȵĽ�������
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
    char* strs;//��ֵ
    if (0 <= pos && pos + num < size && 0 <= num)
    {
        char* sub = new char(num + 1);//������ʱ�ռ�
        const char* strp;
        strncpy(sub, strp + pos, num);
        sub[num] = '\0';
        String cs(sub);
        strcpy(strs, sub);
        return strs;
    }
}
//��������:�ڴ�����s��posλ�ú����һ����t
void String::Insert(String t, int pos)
{
    //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
}
//ɾ�� :ɾ�����е�һ���Ӵ�
void  String::Delete(int pos, int num)
{
    //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
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
