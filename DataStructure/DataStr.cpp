//#include "stdafx.h"
#include <iostream>
#define DataType int
using namespace std;
enum Status { SUCCESS, FAIL, RANGE_ERROR, OVER_FLOW, EMPTY, FULL };
class SeqList
{//���Ա�˳��洢
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
	Status  deleteRange(int i, int j);//ɾ��˳����дӵ�i��λ�ÿ�ʼ������i������j��λ�ã�����j����������������Ԫ��
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
	cout << "����˳���Ԫ��! " << endl;
	for (int j = 1; j < 10; j++)
	{
		sl->insertDate(item);
		i++;

	}
	sl->display();
	for (int j = 1; j < 3; j++)
	{
		cout << "������Ҫ����ĵ�" << j << "������  ";
		cin >> i;
	    item = i;
		cout << "����������Ĳ���λ��!   ";
		cin >> index;
		sl->insertDate(item);
	}
	cout << "success" << endl;
	sl->display();
	i = 1;
	index = 0;
	cout << "������Ҫ���ҵ���!" << endl;
	cin >> i;
	item = i;
	if (sl->locateDate(item) == 0)
	{
		cout << "success" << endl;
	}

	cout << "��ɾ��ֵΪe ������Ԫ�أ�������e��ֵ��" << endl;
	cin >> i;
	item = i;
	sl->deleteMarkDate(item);
	cout << "success" << endl;
	sl->display();


	for (int j = 1; j < 3; j++)
	{
		cout << "������Ҫɾ���ĵ�" << j << "����!  ";
		cin >> i;
	    item = i;
		cout << "�����������λ��!  " << endl;
		cin >> index;
		sl->deleteDate(index, item);
		cout << "success" << endl;
		sl->display();
	}
	int indexa = 0, indexb = 0;
	cout << "������Ҫɾ����������ʼλ�ã�" << endl;
	cin >> indexa;
	cout << "������Ҫɾ���������յ�λ�ã�" << endl;
	cin >> indexb;
	sl->deleteRange(indexa, indexb);
	sl->display();

	return 0;
}
//Status SeqList::insertDate(const DataType& item, int i)
//{
//	int j;
//	if (len == maxLen)              //������
//		return FULL;
//	else if (i<0 || i>len + 1)     //����λ�ó�����Χ
//		return RANGE_ERROR;
//	else {
//		for (j = len; j >= i; j--)
//			data[j] = data[j - 1]; //�������Ԫ��������
//		data[j] = item;        //�����ֵ��ֵ����ǰ�����
//		len++;
//		return SUCCESS;
//	}
//}
Status SeqList::insertDate(const DataType& item)//��������Ԫ��
{
	//1����β��ͷ ���ȶ���λ��
	int i = 0;
	for (int i; i= len - 1; i--) {
		if (item >= data[i])
			break;
		else
		data[i + 1] = data[i];
	}
	//2������
	data[i] = item;
	len++;
	return SUCCESS;
}




Status  SeqList::deleteMarkDate(const DataType& item)
{//ɾ��˳�����ֵΪe������Ԫ��

	for (int i = 0; i < len;) {       //��Ԫ���±�ֵ��ʼѭ������һ��Ԫ���±�Ϊ0
		if (data[i] == item) {               //ѭ���ҳ���i������ֵΪe���ҵ�һ�����ȼ�1
			len--;
			for (int j = i; j < len; j++) {//�ҳ�һ��ѭ����ǰ˳��������Ԫ����ǰ�ƣ��λ��
				data[j] = data[j + 1];     //Ԫ����ǰ�ƶ�
			}
		}
		else
			i++;
	}
	return SUCCESS;
}
Status  SeqList::deleteDate(int i, DataType& d)
{
	//1�����ɾ��λ���Ƿ�Ϸ�
	//2�����ͨ��������Ԫ��������ǰ�ƶ�һ��λ�� 3������1
	//int j;
	if (len == 0)                  //�ձ�
	{
		return FAIL;
	}
	if (i<1 || i>len)             // ɾ��λ�ò��Ϸ�
	{
		return FAIL;
	}
	d = data[i - 1];             //ȡ�߱�ɾԪ�ظ�ֵ��d
	if (i < len)
	{
		for (int k = i; k < len; k++)
		{
			data[k - 1] = data[k]; //�Ӻ��濪ʼ����Ԫ����ǰ�ƶ�
		}
		len--;
		return SUCCESS;
	}
}

Status  SeqList::deleteRange(int i, int j)
{//ɾ��˳����дӵ�i��λ�ÿ�ʼ������i������j��λ�ã�����j����������������Ԫ��

	if (i<1 || i>len&& j<1 || j>len)
		return FAIL;
	for (; j < len; i++, j++)
	{
		data[i - 1] = data[j];  //iλ�õ�jλ��Ԫ�ظ���
	}
	len -= j - i + 1;

	return SUCCESS;

}

Status SeqList::locateDate(DataType item) const
{//��ֵ����

	for (int i = 0; i < len; i++)
		if (data[i] == item)return SUCCESS;
	return FAIL;
}

Status SeqList::getDate(int i, DataType& d) const
{//��ȡָ����ֵ
	if (data[i] == d)
	{
		return SUCCESS;
	}
	return FAIL;

}

void SeqList::display()
{//��ʾ����Ԫ��

	for (int i = 0; i < len; i++)
	{
		cout << data[i] << ",";
	}

}
