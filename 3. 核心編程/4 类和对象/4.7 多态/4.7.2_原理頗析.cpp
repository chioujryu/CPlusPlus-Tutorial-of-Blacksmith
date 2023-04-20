#include<iostream>
using namespace std;

class Animal
{
public:

	//virtual其實是一個指針，指針占了4byte
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	};
	
};

class Cat :public Animal
{
public:
	void speak()	
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


void DoSpeak(Animal & animal)	
{
	animal.speak();
}


void test01()
{
	Cat cat;
	DoSpeak(cat);


	Dog dog;
	DoSpeak(dog);


	Animal animal;
	DoSpeak(animal);
}


void test02()
{
	cout<<sizeof(Animal)<<endl;
}


int main() {

	test02();

	system("pause");

	return 0;
}