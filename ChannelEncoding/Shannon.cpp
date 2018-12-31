#include<iostream>
#include<math.h> 
using namespace std;
void shannon(double *arr,int index) {
	double p1=0;
	for (size_t i = 0; i < index; i++)//注意这里i<7，是因为我们已知数组中有7个数，这里用sizeof的话取的是形参的数据类型
	{
		p1 = arr[i]+p1;
	}
	int K1 = 1 - log2(arr[index]);
	//转为二进制码
	int i = 0; double aM;
	cout <<arr[index]<<"的编码为：";
	while (i < K1) {
		aM = p1 * 2;
		int am = aM;
		cout << am;
		if (aM > 1)
			aM = aM - 1;
		p1 = aM;
		i++;
	}
	cout << endl;
}
/*
void feinuo(double *arr,int index,int time) {
	double sum=0,HalfSum=0;
	for (size_t i = 0; i < time; i++)
	{
		sum += arr[i];
	}
	cout << sum << endl;
	int i = 0;
	while (HalfSum < sum / 2.0) {
		HalfSum += arr[i];
		i++;
		//cout << i << endl;
		time = i--;
	}
	//cout << i << endl;
	if (index < i) {
		cout << "0";
		feinuo(arr, index,time);
	}
	else {
		cout << "1";
		feinuo(arr, index,time);
	}
}*/

int main() {
	/*
	简易版，已知概率,且有序了
	*/
	double a1 = 0.20, a2 = 0.19, a3 = 0.18, a4 = 0.17, a5 = 0.15, a6 = 0.10, a7 = 0.01;
	double arr[] = { 0.20, 0.19, 0.18, 0.17,  0.15, 0.10, 0.01 };
	//把这个输入输出调节成为我们的信源的输入输出

	//shannon(arr, 1);
	for (size_t i = 0; i < sizeof(arr)/8; i++)
	{
		shannon(arr, i);
	}

	//feinuo(arr,1,7);
	system("pause");
	return 0;

}
