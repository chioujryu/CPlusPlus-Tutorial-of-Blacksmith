#include<iostream>
using namespace std;


//1. new的基本語法
int * func()
{
	//在堆區創建整形數據
	//new返回是 該數據類型的指針
	int * p = new int(10);
	return p;
}

int test01() 
{
	int * p = func();
	cout<<*p<<endl;

	//堆區的數據由程序員管理開闢，程序員管理釋放
	//如果想釋放堆區的數據，利用關鍵字delete
	delete p;

	cout<<*p<<endl;	//內存已經被釋放，再訪問一次就會報錯或是亂碼
}

//2. 在堆區利用new開闢數組
void test02()
{
	//創建10個整型數據的數組，在堆區
	int * arr = new int[10];	//10代表數組有10個元素

	for (int i = 0 ; i < 10 ; i++)
	{
		arr[i] = i + 100;	//給10個元素賦予數值  100~109
	}

	//打印數組
	for (int i = 0 ; i < 10 ; i++)
	{
		cout<<arr[i]<<endl;
	}

	//釋放堆區數組
	//釋放數組的時候要加上[]才可以
	delete[] arr;

}

int main(){
	test01();
	test02();
}