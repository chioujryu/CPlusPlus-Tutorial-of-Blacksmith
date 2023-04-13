#include<iostream>
using namespace std;

int * func() //型參數據也會放在棧區
{
	//利用new關鍵字，可以將數據開闢到堆區
	//指針本質也是局部變量，放在棧上，則指針保存的數據是放在堆區
	int * p = new int(10);
	return p;
}

int main(){

	//開闢數據內存
	int * p = func();
	cout<<*p<<endl;		
	
	system("pause");
	return 0;
}