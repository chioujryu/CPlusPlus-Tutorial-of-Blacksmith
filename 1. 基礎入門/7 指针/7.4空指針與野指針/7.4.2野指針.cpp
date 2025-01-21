#include <iostream>
using namespace std;

int main(){

    // 指針變量 p 指向內存地址編號為 0x1100 的空間
    int * p = (int *)0x1100;

    // 訪問野指針報錯
    cout << *p << endl;

    return 0;
}