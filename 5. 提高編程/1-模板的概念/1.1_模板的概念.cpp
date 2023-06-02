# include <iostream>
using namespace std;

//交換兩個整數
void swapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


//交換兩個浮點數
void swapDouble(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}

//函數模板
template<typename T>
void mySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}


void test01(){
    
    //定義參數
    int a = 10;
    int b = 20;
    double c = 10;
    double d = 20;

    //整數交換
    swapInt(a,b);
    cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;

    //浮點數交換
    swapDouble(c,d);
    cout<<"c = "<<c<<"\t"<< "d = "<<d<<endl;

    //利用函數模板交換
    //兩種方式使用函數模板

    //1. 自動類型推倒
    mySwap(a,b);
    cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;

    //2. 顯示指定類型
    mySwap<int>(a,b);
    cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;
}

int main(){
    test01();
}



