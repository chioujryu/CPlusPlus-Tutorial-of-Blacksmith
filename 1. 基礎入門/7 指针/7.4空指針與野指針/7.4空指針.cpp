#include <iostream>
using namespace std;

int main(){

    //指針變量 p 指向內存地址編號為 0 的空間
    int * p = NULL;
    
    //訪問指針報錯
    //內存編號 0 ~ 255 為系統占用內存，不允許用戶訪問
    cout << *p << endl;

    return 0;
}