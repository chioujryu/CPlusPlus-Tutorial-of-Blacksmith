#include <iostream>
using namespace std;


int main(){

    int a = 10;

    int * p;
    p = &a; //指針指向數據a的地址

    cout << *p << endl; // 使用 * 解引用
    cout << sizeof(*p) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(float *) << endl;
    cout << sizeof(double *) << endl; 

    return 0;


}