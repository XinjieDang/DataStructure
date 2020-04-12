#include<iostream>
using namespace std;
int  test() {//输入若干个整数，将它们累加求和，若输入整数为0，则算法结束，并画出输入2，-4,15,0的调用过程
	int data, result;
	data = 0;
	result = 0;
	cout << "请输入数据！";
	cin >> data;
	/*while (data!=0)
	{
		
		result = data+test();        1、输入2   sum=2+test()
									 2、输入-4  sum=-4+test()
									 3、输入15  sum=15+test()
									 4、输入0   sum=0


									 回归调用： 1、 15+test(), 这test()结束的结果就是我们输入0的时候是直接返回 sum=0
												   sum被重新赋值： 故 15+test() 的最终结果是 sum=15+0=15

												2、 -4+test()  test()就是我们输入15后函数的执行 由1得到15+0=15
													sum被重新赋值：故  sum=-4+15=11
												3、2+test()  test()就是我们输入-4后函数的执行，由2得到 -4+15=11
												   sum被重新赋值：故最终 sum的值为 sum=2+11=13




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