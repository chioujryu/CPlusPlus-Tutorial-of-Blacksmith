#include<iostream>
using namespace std;

class Base{

public:

	// 通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
	// 所以可以將虛函數，改成純虛函數
	// 將虛函數，改成純虛函數後，這個類別就變成抽象類，繼承的類別也會是抽象類
	virtual float getResult() = 0;

};

class son: public Base{

public:

	virtual float getResult(){
		cout<<"已調用 son 函數"<<endl;
	};

};

void function(){

	// Base b; // 無法實例化對象，因為這是抽象類
	// new Base  // 無法實例化對象，因為這是抽象類

	son s;	//子類別必須重寫父類別中的純虛函數，不然無法實例化對象
	s.getResult();
	
	Base * b = new son;
	b->getResult();
	delete b;

};

int main(){
	
	function();

}