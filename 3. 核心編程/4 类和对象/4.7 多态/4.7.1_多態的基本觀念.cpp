#include<iostream>
using namespace std;


class Animal
{
public:
	//行為
	//Speak函数就是虚函数
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	//你可以試試看把 virtual 去掉，並編譯看看
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()	//要加virtual或不加virtual都可以
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:

	void speak()	//要加virtual或不加virtual都可以
	{
		cout << "小狗在说话" << endl;
	}

};

//執行說話的還數
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编
//地址早綁定，在編譯階段就可以確定函數的地址
//如果想執行讓貓說話，那麼這個函數地址就不能提前綁定，需要在運行階段進行綁定，地址晚綁定
void DoSpeak(Animal & animal)	//Animal & animal = cat  ，  c++允許父子類型的轉換，很猛吧
{
	animal.speak();
}

//
//多态满足条件： 
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象

void test01()
{
	Cat cat;
	DoSpeak(cat);


	Dog dog;
	DoSpeak(dog);


	Animal animal;
	DoSpeak(animal);
}


int main() {

	test01();

	system("pause");

	return 0;
}