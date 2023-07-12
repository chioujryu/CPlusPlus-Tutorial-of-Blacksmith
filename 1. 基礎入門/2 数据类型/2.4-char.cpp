#include <iostream>
using namespace std;
#include <typeinfo>

int main() {
	
	char ch = 'a';
	cout << "ch = " << ch << endl;
	cout << "sizeof(char) = " <<sizeof(char) << endl;
	cout << "ch 的數據類型為 = " <<typeid(ch).name() << endl;  // 需要 #include <typeinfo>

	//ch = "abcde"; //錯誤，不可以用雙引號
	//ch = 'abcde'; //錯誤，單引號內只能引用一個字符

	cout << "'a'的 ASCII 碼 = " <<(int)ch << endl;  //查看字符a對應的ASCII碼
	ch = 97; //可以直接用ASCII給字符型變量賦值
	cout << "ch = 97時，ASCII碼為 " << ch << endl;

	return 0;
}