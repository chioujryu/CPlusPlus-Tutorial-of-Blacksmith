#include<iostream>
using namespace std;

void swap01(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swap02(int * p1, int * p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}

int main(){

    //指針和函數
    //1.值傳遞
    //值傳遞不能變更實參
    int a = 10;
    int b = 20;
    swap01(a,b);
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;


    //2. 地址傳遞
    //如果是地址傳遞，可以修飾實參
    swap02(&a,&b);
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;

    return 0;


    //如果想修改實參，就用地址傳遞
    //如果不想修改實參，就用值傳遞
}