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
//生成新字符串函数
void String::Creat()
{
    char* s = new char(100);
    cin >> s;
    size = strlen(s);
    str = new char[size];
    if (str == 0)  cout << "没有申请到空间！";
    strcpy(str, s);
}
//输出
void String::Display()
{
    int i;
    for (i = 0; i < size; i++)  cout << str[i];
    cout << endl;
}
//求子串
String String::SubString(int pos, int num)
{
    //将此成员函数补充完整，使得程序能够正确运行
    String strs;
    if (pos >= 0 && pos < size)//判断截取位置
    {
        strs.str = new char[num + 1];// 申请临时空间
        for (int i = 0; i < num; i++)// 截取str 0-n中的字符
        {
            strs.str[i] = str[pos + i - 1];
        }
        strs.str[num] = '\0';
        strs.size = num;//设置 str 大小
        return strs;
    }
    else
    {
        strs.size = -1;
        return strs;
    }

}
//插入运算:在串对象s的pos位置后插入一个串t
void String::Insert(String t, int pos)
{
    //将此成员函数补充完整，使得程序能够正确运行
    if (pos<0 || pos>size)
    {
        cout << "插入位置错误";
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
//删除 :删除串中的一个子串
void  String::Delete(int pos, int num)
{
    //将此成员函数补充完整，使得程序能够正确运行
    if (pos<0 || pos>size)
    {
        cout << "输入的位置非法";
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
//主函数
int main(int argc, char* argv[])
{
    int pos, num, k;
    String s, s1, t;
    do {
        cout << "\n\n    1.生成字符串";
        cout << "\n\n    2.取子串";
        cout << "\n\n    3.插入子串s1";
        cout << "\n\n    4.删除子串";
        cout << "\n\n    5.结束程序";
        cout << "\n******************************** ";
        cout << "\n    请输入你的选择(1,2,3,4,5)";  cin >> k;
        switch (k) {
        case 1: {cout << "请输入一个字符串：";
            s.Creat();
            cout << "字符串为：       ";     s.Display();
        }break;
        case 2: { cout << "请输入子串的截取位置pos及子串长度num" << endl;
            cin >> pos >> num;
            t = s.SubString(pos, num);
            cout << "你所取的子串为：　　";  t.Display();
        }break;
        case 3: { cout << "请输入子串插入位置pos" << endl;
            cin >> pos;
            cout << "请输入要插入的子串:  ";   s1.Creat();
            s.Insert(s1, pos);
            cout << "插入后的字符串为：   ";  s.Display();
        }break;
        case 4: { cout << "请输入要删除子串的开始位置pos及子串长度num" << endl;
            cin >> pos >> num;
            s.Delete(pos, num);
            cout << "删除后的字符串为：   ";
            s.Display();
        }break;
        default:break;
        } //switch
        cout << "\n--------------------------------- ";
    } while (k >= 1 && k < 5);
    cout << "\n          再见!";
    cout << "\n     按任意键，返回。";
    return 0;
}
