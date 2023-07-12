#include <iostream>
using namespace std;
#include <typeinfo>

int main() {

	bool flag = true;
	cout << "true = " <<flag << endl; // 1

	flag = false;
	cout << "false = " << flag << endl; // 0

	cout << "size of bool = " << sizeof(bool) << endl; //1

    cout << "flag 的數據類型為 = " <<typeid(flag).name() << endl;  // 需要 #include <typeinfo>

	return 0;
}