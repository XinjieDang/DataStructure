#include<iostream>
using namespace std;
int  test() {//�������ɸ��������������ۼ���ͣ�����������Ϊ0�����㷨����������������2��-4,15,0�ĵ��ù���
	int data, result;
	data = 0;
	result = 0;
	cout << "���������ݣ�";
	cin >> data;
	/*while (data!=0)
	{
		
		result = data+test();        1������2   sum=2+test()
									 2������-4  sum=-4+test()
									 3������15  sum=15+test()
									 4������0   sum=0


									 �ع���ã� 1�� 15+test(), ��test()�����Ľ��������������0��ʱ����ֱ�ӷ��� sum=0
												   sum�����¸�ֵ�� �� 15+test() �����ս���� sum=15+0=15

												2�� -4+test()  test()������������15������ִ�� ��1�õ�15+0=15
													sum�����¸�ֵ����  sum=-4+15=11
												3��2+test()  test()������������-4������ִ�У���2�õ� -4+15=11
												   sum�����¸�ֵ�������� sum��ֵΪ sum=2+11=13




		data = 0;
	}
	return result;*/
	if (data != 0) {
		result = data + test();
	}
	else
		return result;
	//return result;
	

}
int main() {
	cout << test() << endl;
	system("pause");
	return 0;
}