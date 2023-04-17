//*********成员变量和成员函数分开存储*********
//在C++中，类内的成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上

#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		mA = 0;
	}
	//非静态成员变量占对象空间
	int mA;
	//静态成员变量不占对象空间
	static int mB; 
	//函数也不占对象空间，所有函数共享一个函数实例
	void func() {
		cout << "mA:" << this->mA << endl;
	}
	//静态成员函数也不占对象空间
	static void sfunc() {
	}
};

int Person::mB = 10;

class cat{
	
};

void test(){
	//空對象占用內存空間為1
	//c++編譯器會給每個空對象也分配一個字節的空間，是為了區分空對象占內存的位置
	//每個空對象，也應該有獨一無二的內存地址
	cat c1;
	cout<<"空對象c1的大小為多少：" <<sizeof(c1)<<endl;
};

int main() {

	test();

	Person p;
	cout << "Person類的大小為" <<sizeof(Person) << endl;		//因mA的大小有4byte，所以Person類的大小為4byte
	cout<<"p的地址為：" <<(int)&p<<endl;
	cout<<"p.mA的地址為："<<(int)&p.mA<<endl;
	cout<<"靜態變量`mB`的地址為："<<(int) & Person::mB<<endl;

	system("pause");

	return 0;
}