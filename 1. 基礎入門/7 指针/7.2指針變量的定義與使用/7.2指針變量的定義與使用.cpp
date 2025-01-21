#include <iostream>
using namespace std;


int main(){

    //1. 指針的定義
    int a = 10; //定義整形變量a

    // 指針定義與法:數據類型
    int * p;

    //指針變量賦值
    p = &a;
    cout << &a << endl; //打印數據 a 的地址
    cout << p << endl; // 打印指針變量 p

    // 2. 指針的使用
    // 通過 * 操作指針變量指向的內存
    cout << "*p = " << *p <<endl;

    return 0;
}