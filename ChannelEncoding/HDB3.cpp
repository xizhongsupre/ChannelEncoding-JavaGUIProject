#include<iostream>
#include<fstream>
using namespace std;
int main() {
	cout << "------------------HDB3编码------------------" << endl;
	//读取文件中的字符
	fstream OpenFile("F://test.txt");
	char ch;
	int Sign[23], i = 0,a;
	while (!OpenFile.eof()) {
		OpenFile.get(ch);
		a = (int)ch-48;
		Sign[i] = a;
		i++;
	}
	//cout << "请依次输入你的数字信号，一次不要超过13个" << endl;
	int index = 0, temp = 0, symble[sizeof(Sign) / 4];
	for (int i = 0; i < sizeof(Sign) / 4; i++) {
		if (Sign[i] != 1) {
			//记录连续出现0的个数以及由几个4连0的情况
			++index;
			if (index >= 4 && index % 4 == 0) {
				++temp;
				symble[temp - 1] = i;//标识每一次出现4连0时i的位置
			}
		}
		else {
			index = 0;
		}
	}
	for (size_t i = 0; i < sizeof(Sign)/4-1; i++)
	{
		cout << Sign[i];
	}
	cout << "\n\n";

	/*int index = 0, temp = 0, symble[sizeof(Sign) / 4];
	for (int i = 0; i < sizeof(Sign) / 4; i++) {
		cin >> Sign[i];
		if (Sign[i] != 1) {
			//记录连续出现0的个数以及由几个4连0的情况
			++index;
			if (index >= 4 && index % 4 == 0) {
				++temp;
				symble[temp - 1] = i;//标识每一次出现4连0时i的位置
			}
		}
		else {
			index = 0;
		}

	}*/
	for (size_t i = 0; i < sizeof(symble)/4-21; i++)
	{
		//cout << symble[i] << endl;//为了输出我们的V的位置
	}
	
	int ts[sizeof(Sign) / 4], t = 1;
	ts[0] = 0;//定义ts[0]是为了使得ts数组能够记录numbersOfEqual_1_BetweenVandV的值
	int sum = 0;//sum记录极性和
	int x = 0;//用来标识是第几次碰到了四连0的情况
	for (int i = 0; i < sizeof(Sign) / 4; i++) {
		//如果不含有4连0的情况，也就是temp==0的时候，HDB3和AMI是一样的。
		sum += Sign[i];
		if (temp == 0) {
			if (Sign[i] == 0)
				cout << "--";
			else {
				if (sum % 2 == 0)
					cout << "__";
				else
					cout << "~~";
			}
		}
		
		//如果含有4连0的情况时
		if (temp != 0) {
			if (Sign[i] == 0) {
				if (i != (symble[x]-3))//注意这里是减3而不是减去4，因为循环使得i++
					cout << "--";
				else {
					//这个时候处于四连零0000中的第一个“0”位置上，必须先输出该位置的波型

					//定义numbersOfEqual_1_BetweenVandV来记录两个V之间有奇数个还是偶数个“1”
					int numbersOfEqual_1_BetweenVandV=0;
					if (symble[x + 1] < sizeof(Sign)/4) {//注意这里如果symble[x+1]<Sign的长度是会数组越界问题的
						for (int a = symble[x]; a < symble[x + 1]; a++) {
							if (Sign[a] == 1)
								numbersOfEqual_1_BetweenVandV++;
						}
					}
					//numbersOfEqual_1_BetweenVandV的值是随着x++而变化的，所以保留住之前的numbersOfEqual_1_BetweenVandV用来判断
					ts[t] = numbersOfEqual_1_BetweenVandV;
					
					//判断0000如何变化
					if (ts[t-1]>0 && ts[t-1] % 2 == 0) {
						//这是0000变成B00V的时候
							if (sum % 2 == 0) cout << "~~";
							else cout << "__";
							Sign[i + 3] = 1;
							//sum = sum - 2;//因为这里两次0000变成B00V,这里两次变为1，其实对于sum%2来说相当于没变化，故此句可要可不要
					}
					else
					{	//这是0000变成000V的时候
						cout << "--";
						if (sum % 2 != 0) {
							Sign[i + 3] = 1;
							sum = sum - 1;//因为第一次V：000V中V变成1,其实给sum+1,所以这里减一下
						}
					}	
				x++,t++;
				}
			}
			else {
					if (sum % 2 == 0)
						cout << "__";
					else
						cout << "~~";
			}
		}
	}
	system("pause");
	return 0;

}
