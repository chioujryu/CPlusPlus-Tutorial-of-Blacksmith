//*********const修飾成員函數*********

#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		m_A = 0;
		m_B = 0;
	}

	//常量函數
	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	//在成員函數後面加上const，修飾的是this指向，讓指針指向的值都不可以修改
	void ShowPerson() const {
		//const Person * const this; 這代表指針的指向跟裡面的值都不能修改
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的
		

		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
	}

	void MyFunc() const{		
		//m_A = 10000;
		cout<<"我調用了MyFunc"<<endl;
	}

public:
	int m_A;
	mutable int m_B; //特殊關鍵字mutable，加上這個關鍵字，即使在常量函數中，也可以修改這個值
};

//const修饰对象  常量对象
void test01() {

	const Person person; //常量对象  
	cout << person.m_A << endl;
	//person.mA = 100; //常量对象 不能修改成员变量的值,但是可以访问
	person.m_B = 100; //m_B因為有加上mutable關鍵字，所以可以修改他

	//常量对象 只能調用常量函數
	person.MyFunc();
}

int main() {

	test01();

	system("pause");

	return 0;
}