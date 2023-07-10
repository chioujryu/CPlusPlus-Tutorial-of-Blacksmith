#include <iostream>
using namespace std;

int main() {
	
	char ch = 'a';
	cout << ch << endl;
	cout << sizeof(char) << endl;

	//ch = "abcde"; //錯誤，不可以用雙引號
	//ch = 'abcde'; //錯誤，單引號內只能引用一個字符

	cout << "'a'的 ASCII 碼 = " <<(int)ch << endl;  //查看字符a對應的ASCII碼
	ch = 97; //可以直接用ASCII給字符型變量賦值
	cout << ch << endl;

	return 0;
}