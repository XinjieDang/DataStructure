
#include <iostream>
#define DataType int
using namespace std;
enum Status { SUCCESS, FAIL, RANGE_ERROR, OVER_FLOW, EMPTY, FULL };
class SeqList
{
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
	Status  insertDate(const DataType& item, int i);
	Status  deleteDate(int i, DataType& d);
	Status  deleteRange(int i, int j);//ɾ��˳����дӵ�i��λ�ÿ�ʼ������i������j��λ�ã�����j����������������Ԫ��
	Status  deleteAllelem(int e);
	void display();
	void textDisplay();
};
SeqList::SeqList(int size)
{
	data = new DataType[size];
	len = 0;
	maxLen = size;
}
SeqList::~SeqList()
{
	delete[]data;
}
Status SeqList::insertDate(const DataType& item, int i)
{
	int j;
	if (len == maxLen)
		return FULL;
	else if (i<0 || i>len + 1)
		return RANGE_ERROR;
	else
	{
		for (j = len; j >= i; j--)
		{
			data[j] = data[j - 1];

		}
		data[j] = item;
		len++;
		return SUCCESS;
	}

}
Status  SeqList::deleteDate(int i, DataType& d)
{

	if (len > 0)
	{
		for (int j = i; j <= len; j++)
		{
			data[j - 1] = data[j];

		}
		len--;
		return SUCCESS;
	}
	else return FULL;



}

Status  SeqList::deleteRange(int i, int j)
{//ɾ��˳����дӵ�i��λ�ÿ�ʼ������i������j��λ�ã�����j����������������Ԫ��

	if (((i < 1) || (i > len)) && ((j < 1) || (j < len)))
		return FULL;
	for (; j < len; i++, j++)
	{
		data[i - 1] = data[j];
	}

	len -= j - i + 1;
	return SUCCESS;
}

Status  SeqList::deleteAllelem(int e) //ɾ��˳�����ֵΪe������Ԫ��
{
	for (int i = 0; i < len;) {
		if (data[i] == e) {

			len--;
			for (int j = i; j < len; j++) {
				data[j] = data[j + 1];
			}
		}
		else
			i++;
	}
	return SUCCESS;
}

Status SeqList::locateDate(DataType item) const
{
	return SUCCESS;
}
Status SeqList::getDate(int i, DataType& d) const
{
	return SUCCESS;
}

void SeqList::display()
{

	int i;
	for (i = 0; i < len; i++)
	{

		cout << data[i] << ",";

	}

}

void SeqList::textDisplay()
{
	data[8] = data[4] = data[6] = data[3];
	int i;
	for (i = 0; i < len; i++)
	{

		cout << data[i] << ",";

	}
}

int main()
{

	SeqList* sl = new SeqList(20);
	DataType i = 3;
	DataType& item = i;





	for (int j = 1; j <= 10; j++)
	{
		sl->insertDate(item, j);
		i++;
	}

	cout << "�����" << endl;
	sl->display();
	cout << " " << endl;
	// sl->deleteDate(2, item);
	 //sl->deleteRange(2, 10);

	 //sl->textDisplay();


	int e;
	int pos;//λ��
	DataType ee;
	cout << "������e��ֵ�����ĸ�λ�ò��룺" << endl;
	cin >> ee;
	DataType& item1 = ee;
	cin >> pos;
	sl->insertDate(item1, pos);
	//sl->textDisplay();
	sl->display();
	int ex;
	cout << "������Ҫɾ����ֵ��" << endl;
	cin >> ex;



	sl->deleteAllelem(ex);//ɾ����ֵΪ6������Ԫ��
	cout << " " << endl;
	sl->display();




	return 0;
}

