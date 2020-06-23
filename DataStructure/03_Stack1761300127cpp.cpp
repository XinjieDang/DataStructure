
//栈的顺序存储结构，顺序表类
#include<iostream>
#include<conio.h>
#include <iomanip>
using namespace std;
//------------------------------栈的顺序存储结构---------------------------------------------
typedef char  ElemType;     // 数据元素的类型
const int MAXSIZE = 50;     // 数组的容量
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
    void InitStack();
    bool BracketsCheck(char* str);
};
//-------------------------------------------------------------
SqStack::SqStack(void) :top(0) { }
int  SqStack::SetEmpty()
{
    return top == 0;
}
void  SqStack::push( const ElemType e)
{
    //将此成员函数补充完整，使得程序能够正确运行
    if (top == MAXSIZE)//顺序栈已满
        cout << "顺序栈已满!";
    else
    {
        elem[++top] = e;//将元素e追加到栈顶，且top加一
        cout << "入栈SUCCESS" << endl;

    }

}
ElemType SqStack::pop()
{
    //将此成员函数补充完整，使得程序能够正确运行
    ElemType e;
    if (IsEmpty() == 1)
        cout << "当前是空栈!";
    else
    {
        e = elem[top--];//用e 返回栈顶元素，且栈顶指针减一
        cout << "出栈SUCCESS" << endl;
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

void SqStack::InitStack() {//创建空栈
    top = 0;
}

bool SqStack::BracketsCheck(char* str)//括号匹配
{
    int i = 0;
    char temp = NULL;
    while (str[i] != '\0') {
        switch (str[i]) {//判断遇到的括号是不是左括号({[，是则入栈
        case '(': 
            push('(');
            break;
        case '{':
            push('{');
            break;
        case '[':
            push('[');
            break;
        case '}'://判断遇到的是不是右括号，是则将当前栈顶元素出栈，与右括号比较,若匹配则继续往下扫描
            temp=pop();
            if (temp != '{') {//
                printf("括号不匹配\n");
                return false;
            }
            break;
        case ')':
            temp = pop();
            if (temp != '(') {
                printf("括号不匹配\n");
                return false;
            }
            break;
        case ']':
            temp = pop();
            if (temp != '[') {
                printf("括号不匹配\n");
                return false;
            }
            break;
        default:
            break;
        }
        i++;//扫描下一个元素
    }
    if (!IsEmpty()) {
        printf("括号不匹配\n");
        return false;
    }
    else {
        printf("括号匹配\n");
        return true;
    }


}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int i, k;
    ElemType e, x;
    SqStack  as;
    cout << "\n                           栈的顺序存储结构实现";
    do {
        cout << "\n\n";
        cout << "\n\n    1.插入一个数据元素e（入栈）";
        cout << "\n\n    2.删除一个元素，返回其值（出栈）";
        cout << "\n\n    3..括号匹配";
        cout << "\n\n    4..结束程序";
        cout << "\n******************************** ";
        cout << "\n    请输入你的选择(1,2,3,4,5,6)";    cin >> k;
        switch (k) {
        case 1: {cout << "\n 入栈，数据 e=?";
            cin >> e;
            as.push(e);
            as.PrintOut();
        }break;
        case 2: {  cout << "\n 出栈";
            x = as.pop();
            cout << "\n  出栈元素数值= " << x<<endl;
            cout << "栈内剩余元素为：";
            as.PrintOut();
        }break;
        case 3:
        {  cout << "\n 括号匹配,请输入表达式";
        char brackets[10]; 
        cin >> brackets;
        as.InitStack();//清空栈
        as.BracketsCheck(brackets);
        }break;
        default:break;
        } //switch
        cout << "\n--------------------------------- ";
    } while (k >= 1 && k < 5);
    cout << "\n          再见!";
    cout << "\n     按任意键，返回。";
    _getch(); return 0;
}
//-----------------------------------------------

