
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
	Status  deleteRange(int i, int j);//删除顺序表中从第i个位置开始（包括i）到第j个位置（包括j）结束的所有数据元素
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
{//删除顺序表中从第i个位置开始（包括i）到第j个位置（包括j）结束的所有数据元素

	if (((i < 1) || (i > len)) && ((j < 1) || (j < len)))
		return FULL;
	for (; j < len; i++, j++)
	{
		data[i - 1] = data[j];
	}

	len -= j - i + 1;
	return SUCCESS;
}

Status  SeqList::deleteAllelem(int e) //删除顺序表中值为e的所有元素
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

	cout << "有序表" << endl;
	sl->display();
	cout << " " << endl;
	// sl->deleteDate(2, item);
	 //sl->deleteRange(2, 10);

	 //sl->textDisplay();


	int e;
	int pos;//位置
	DataType ee;
	cout << "请输入e的值与在哪个位置插入：" << endl;
	cin >> ee;
	DataType& item1 = ee;
	cin >> pos;
	sl->insertDate(item1, pos);
	//sl->textDisplay();
	sl->display();
	int ex;
	cout << "请输入要删除的值：" << endl;
	cin >> ex;



	sl->deleteAllelem(ex);//删除定值为6的所有元素
	cout << " " << endl;
	sl->display();




	return 0;
}

