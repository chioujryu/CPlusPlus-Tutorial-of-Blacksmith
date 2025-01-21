#include <iostream>
using namespace std;


int main(){

    int a = 10;
    int b = 10;

    //const修飾的是指針指向的值，指針指向可以改，指針指向的值不可以更改
    const int * p1 = &a;
    p1 = &b; //正確
    // *p1 = 100; //報錯

    //const p2 是一個常量(意味著 p2不能被修改)，也就是說p2必須一直指向初始化時的地址(這裡是&a)
    // 然而，指針指向的內容(*p2)是可以更改的
    int * const p2 = &a;
    // p2 = &b //錯誤
    *p2 = 100; //正確

    //const 既修飾指針又修飾常量
    const int * const p3 = &a;
    //p3 = &b; //錯誤
    //*p3 = 100; //錯誤

    return 0;
}