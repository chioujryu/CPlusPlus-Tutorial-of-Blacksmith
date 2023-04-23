#include<iostream>
using namespace std;

//Animal類
//因裡面有純虛函數，所以這是抽象類
class Animal{
public:
	Animal(){
		cout<<"Animal構造函數調用"<<endl;
	};

	// //析构函数加上virtual关键字，变成虚析构函数
	// virtual ~Animal(){
	// 	cout<<"Animal析構函數調用"<<endl;
	// }
	
	virtual ~Animal() = 0;	//或是寫成純虛析構也可以，不過一定要在類外做具體的實現

	//純虛函數
	virtual void speak() = 0;

protected:
	string * m_name;
};

Animal::~Animal()
{
	cout << "Animal 纯虚析构函数调用！" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
//Cat類
class Cat: public Animal{
public:
	Cat(string name){
		cout<<"Cat構造函數調用"<<endl;
		this->m_name = new string(name);
	};
	~Cat(){
		cout<<"Cat析構函數調用"<<endl;
		if(this->m_name != NULL){
			delete m_name;
			m_name = NULL;
		};
	};
	//虛函數
	virtual void speak(){
		cout<<"小貓在說話"<<endl;
	};
};

void Speak(){

	Animal * animal = new Cat("Tom Cat");
	animal->speak();

	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
};

int main(){
	
	Speak();
	return 0;

};