#include<iostream>
using namespace std;
#include <conio.h>
#include <string.h>//c++ 串库
class String
{
public:
    String()//初始化一个空串
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
    char* str;//串值
    int size;//串长
};
//生成新字符串函数
void String::Creat()
{
    char* s = new char(100);
    cin >> s;
    size = strlen(s); //strlen 串长度
    str = new char[size];
    if (str == 0)  cout << "没有申请到空间！";
    //strcpy函数
    //就是将 s字符数组复制到str数组中，如果str数组本身有数据，
    //会把s里的数据全部复制到str中，如果str中有数据小于s地址长度的将会被覆盖，而大于s长度的将保留。
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
    char* strs;//串值
    if (0 <= pos && pos + num < size && 0 <= num)
    {
        char* sub = new char(num + 1);//申请临时空间
        const char* strp;
        strncpy(sub, strp + pos, num);
        sub[num] = '\0';
        String cs(sub);
        strcpy(strs, sub);
        return strs;
    }
}
//插入运算:在串对象s的pos位置后插入一个串t
void String::Insert(String t, int pos)
{
    //将此成员函数补充完整，使得程序能够正确运行
}
//删除 :删除串中的一个子串
void  String::Delete(int pos, int num)
{
    //将此成员函数补充完整，使得程序能够正确运行
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
