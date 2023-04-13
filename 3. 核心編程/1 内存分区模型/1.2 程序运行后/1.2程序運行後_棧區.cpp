#include<iostream>
using namespace std;

//棧區數據的注意事項 -- 不要返回局部變量的地址
//棧區的數據由編譯器管理開闢與釋放

int * func(int b) //型參數據也會放在棧區
{
	b = 100;
	int a = 10;	//局部變量，存放在棧區，棧區的數據在函數執行完後自動釋放
	return &a;	//返回局部變量的地址
}

int main(){

	int * p = func(1);	//第一次可以打印正確的數字，是因為編譯器做了保留
	cout<<*p<<endl;		//第二次這個數據就不再保留了
	return 0;
}