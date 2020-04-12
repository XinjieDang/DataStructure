//#include "stdafx.h"
#include <iostream>
#define DataType int
using namespace std;
enum Status { SUCCESS, FAIL, RANGE_ERROR, OVER_FLOW, EMPTY, FULL };
class SeqList
{//线性表顺序存储
private:
	DataType* data;
	int len;
	int maxLen;
public:
	SeqList(int size);
	~SeqList();
	int  length() const;
	Status  getDate(int i, DataType& d) const;
	Status  locateDate(DataType x) const;
	Status  insertDate(const DataType& item);
	Status  deleteMarkDate(const DataType& item);
	Status  deleteDate(int i, DataType& d);
	Status  deleteRange(int i, int j);//删除顺序表中从第i个位置开始（包括i）到第j个位置（包括j）结束的所有数据元素
	void display();
};

SeqList::SeqList(int size)
{
	data = new DataType[size];
	len = 0;
	maxLen = size;
}

SeqList::~SeqList()
{
	delete[] data;
}
int main(int argc, char** argv)
{
	int index = 0;
	SeqList* sl = new SeqList(30);
	DataType i = 1;
	DataType& item = i;
	cout << "生成顺序表元素! " << endl;
	for (int j = 1; j < 10; j++)
	{
		sl->insertDate(item);
		i++;

	}
	sl->display();
	for (int j = 1; j < 3; j++)
	{
		cout << "请输入要插入的第" << j << "个数！  ";
		cin >> i;
	    item = i;
		cout << "请输入该数的插入位置!   ";
		cin >> index;
		sl->insertDate(item);
	}
	cout << "success" << endl;
	sl->display();
	i = 1;
	index = 0;
	cout << "请输入要查找的数!" << endl;
	cin >> i;
	item = i;
	if (sl->locateDate(item) == 0)
	{
		cout << "success" << endl;
	}

	cout << "将删除值为e 的所有元素，请输入e的值！" << endl;
	cin >> i;
	item = i;
	sl->deleteMarkDate(item);
	cout << "success" << endl;
	sl->display();


	for (int j = 1; j < 3; j++)
	{
		cout << "请输入要删除的第" << j << "个数!  ";
		cin >> i;
	    item = i;
		cout << "请输入该数的位置!  " << endl;
		cin >> index;
		sl->deleteDate(index, item);
		cout << "success" << endl;
		sl->display();
	}
	int indexa = 0, indexb = 0;
	cout << "请输入要删除的区间起始位置！" << endl;
	cin >> indexa;
	cout << "请输入要删除的区间终点位置！" << endl;
	cin >> indexb;
	sl->deleteRange(indexa, indexb);
	sl->display();

	return 0;
}
//Status SeqList::insertDate(const DataType& item, int i)
//{
//	int j;
//	if (len == maxLen)              //表已满
//		return FULL;
//	else if (i<0 || i>len + 1)     //插入位置超出范围
//		return RANGE_ERROR;
//	else {
//		for (j = len; j >= i; j--)
//			data[j] = data[j - 1]; //插入点后的元素往后移
//		data[j] = item;        //插入的值赋值给当前插入点
//		len++;
//		return SUCCESS;
//	}
//}
Status SeqList::insertDate(const DataType& item)//有序表插入元素
{
	//1、从尾到头 ，比对找位置
	int i = 0;
	for (int i; i= len - 1; i--) {
		if (item >= data[i])
			break;
		else
		data[i + 1] = data[i];
	}
	//2、插入
	data[i] = item;
	len++;
	return SUCCESS;
}




Status  SeqList::deleteMarkDate(const DataType& item)
{//删除顺序表中值为e的所有元素

	for (int i = 0; i < len;) {       //以元素下标值开始循环，第一个元素下标为0
		if (data[i] == item) {               //循环找出第i个符合值为e，找到一个长度减1
			len--;
			for (int j = i; j < len; j++) {//找出一个循环当前顺序表，后面的元素往前移，填补位置
				data[j] = data[j + 1];     //元素往前移动
			}
		}
		else
			i++;
	}
	return SUCCESS;
}
Status  SeqList::deleteDate(int i, DataType& d)
{
	//1、检查删除位置是否合法
	//2、检查通过，数据元素依次向前移动一个位置 3、表长减1
	//int j;
	if (len == 0)                  //空表
	{
		return FAIL;
	}
	if (i<1 || i>len)             // 删除位置不合法
	{
		return FAIL;
	}
	d = data[i - 1];             //取走被删元素赋值给d
	if (i < len)
	{
		for (int k = i; k < len; k++)
		{
			data[k - 1] = data[k]; //从后面开始后面元素往前移动
		}
		len--;
		return SUCCESS;
	}
}

Status  SeqList::deleteRange(int i, int j)
{//删除顺序表中从第i个位置开始（包括i）到第j个位置（包括j）结束的所有数据元素

	if (i<1 || i>len&& j<1 || j>len)
		return FAIL;
	for (; j < len; i++, j++)
	{
		data[i - 1] = data[j];  //i位置到j位置元素覆盖
	}
	len -= j - i + 1;

	return SUCCESS;

}

Status SeqList::locateDate(DataType item) const
{//按值查找

	for (int i = 0; i < len; i++)
		if (data[i] == item)return SUCCESS;
	return FAIL;
}

Status SeqList::getDate(int i, DataType& d) const
{//获取指定的值
	if (data[i] == d)
	{
		return SUCCESS;
	}
	return FAIL;

}

void SeqList::display()
{//显示所有元素

	for (int i = 0; i < len; i++)
	{
		cout << data[i] << ",";
	}

}
