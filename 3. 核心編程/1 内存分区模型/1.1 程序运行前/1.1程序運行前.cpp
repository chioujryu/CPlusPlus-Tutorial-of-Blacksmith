#include<iostream>
using namespace std;

//全局變數
int g_a = 10;
int g_b = 10;

//const修飾的全局變數 = 全局常數
const int c_g_a = 10;
const int c_g_b = 10;


int main(){

    //創建普通局部變數
    int a = 10;
	int b = 10;

    //打印地址
	cout << "局部變數a地址为： " << (int)&a << endl;
	cout << "局部變數b地址为： " << (int)&b << endl;

	cout << "全局變數g_a地址为： " <<  (int)&g_a << endl;
	cout << "全局變數g_b地址为： " <<  (int)&g_b << endl;

    //靜態變量，在普通便量前面加static，就屬於靜態變量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态變數s_a地址为： " << (int)&s_a << endl;
	cout << "静态變數s_b地址为： " << (int)&s_b << endl;

    //常數
    //字符串常數
	cout << "字符串常數地址为： " << (int)&"hello world" << endl;
	cout << "字符串常數地址为： " << (int)&"hello world1" << endl;

    //const修飾的變數、
    //const修飾的全局變數
	cout << "全局常數c_g_a地址为： " << (int)&c_g_a << endl;
	cout << "全局常數c_g_b地址为： " << (int)&c_g_b << endl;

    //const修飾的局部變數
    //c-const   g-global    l-local
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常數c_l_a地址为： " << (int)&c_l_a << endl;
	cout << "局部常數c_l_b地址为： " << (int)&c_l_b << endl;

	system("pause");

	return 0;
}