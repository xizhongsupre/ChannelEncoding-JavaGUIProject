#include<iostream>
using namespace std;
int main() {
	cout << "---------------------------AMI编码-------------------------" << endl;
	cout << "请输入你的信号(一次输入不要超过13个)：";
	int sign,Sign[13];
	//cout << sizeof(Sign)/4;
	for (int i = 0; i < sizeof(Sign) / 4; i++) {
		cin >> Sign[i];
	}
	//读取信号并输出到屏幕
	int temp = 0;
	for (int i = 0; i < sizeof(Sign)/4; i++) {
		if (Sign[i] != 0)
			temp += 1;
		if (Sign[i] == 0) {
			cout << "--";
		}
		else {
			if (temp% 2 != 0) {
				cout << "~~"; 
			}
			else {
				cout << "__";
			}
		}
	}
	
	system("pause");
	return 0;

}
