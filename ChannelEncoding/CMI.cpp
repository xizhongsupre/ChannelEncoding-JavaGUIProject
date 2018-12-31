#include<iostream>
using namespace std;
int main() {
	cout << "-----------------CMI-----------------" << endl;
	cout << "请输入你的信号(10个信号为一组）：" << endl;
	int sign, Sign[10];
	for (int i = 0; i < sizeof(Sign)/4; i++) {
		cin >> Sign[i];
	}
	/*int value = 0,i=0;
	while (cin >> value) {
		cin >> sign >> sign[i];
		i++;
	}*/
	cout << "编码效果：" << endl;  cout << endl;
	
	int sum = 0, temp = 0;
	for (size_t i = 0; i < 10; i++)
	{
		//cout << Sign[i]<<endl;
		/*for (size_t i = 0; i < 10; i++)
			{
				if (Sign[i] = 0)  cout << "_-";
				int sum = 0;
				sum += Sign[i];
				if (sum % 2 != 0) {
					cout << "--";
				}
				else cout << "__";
			}*/
		temp = sum;
		sum += Sign[i];

		if (sum == temp) {
			cout << "_-";
		}
		else {
			if (sum % 2 == 0) cout << "__";
			else cout << "--";
		}
	}
	cout << "\n\n编码完毕！" << endl;
	system("pause");
	return 0;
}