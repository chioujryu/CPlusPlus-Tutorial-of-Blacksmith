#include <iostream>
using namespace std;

int main(){

	//整型輸入
	int a = 0;
	cout << "請輸入整型變量：" << endl;
	cin >> a;
	cout << "妳的輸入為 = " << a << endl;

	//浮點型輸入
	double d = 0;
	cout << "請輸入浮點型變量：" << endl;
	cin >> d;
	cout << "妳的輸入為 = " << d << endl;

	//字符型輸入
	char ch = 0;
	cout << "請輸入字符型變量：" << endl;
	cin >> ch;
	cout << "妳的輸入為 = " << ch << endl;

	//字符串型輸入
	string str;
	cout << "請輸入字符串型變量：" << endl;
	cin >> str;
	cout << "妳的輸入為 = " << str << endl;

	//布爾類型輸入
	bool flag = true;
	cout << "請輸入布爾型變量：" << endl;
	cin >> flag;
	cout << "妳的輸入為 = " << flag << endl;

	return EXIT_SUCCESS;
}