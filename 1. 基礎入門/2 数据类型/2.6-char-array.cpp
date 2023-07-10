#include <iostream>
using namespace std;

int main() {

char str1[] = "Hello world";
cout << str1 << endl;

// 一個是字符'Hello world'，另一個是終止空字符'\0'，所以 sizeof 為 12
cout<<sizeof(str1)<<endl; 

int numArray[] = {1,2,3,4,5,6};
cout<<sizeof(numArray)<<endl; 


// C++ 風格用法
string str = "hello world";
cout << str << endl;

cout<<sizeof(str)<<endl;  // string 占了兩個字節

return 0;
}