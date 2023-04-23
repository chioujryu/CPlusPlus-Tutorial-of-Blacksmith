#include<iostream>
using namespace std;

// 多態的好處
// 1. 組織結構清晰
// 2. 可讀性強
// 3. 對於前期以及後期的維護性高

class  AbstractCalculator{
public:
	float number1;
	float number2;
public:
	//初始值設定
	AbstractCalculator(){
		this->number1 = 0;
		this->number2 = 0;
	};

public:

	virtual float getResult(){	//operator是c++的保留字，所以變數名稱不能用operator
		return 0;
	};

};

class CalculatorAdd: public AbstractCalculator{
public:
	float getResult(){
		return number1 + number2;
	}
};

class CalculatorSubstract: public AbstractCalculator{
public:
	float getResult(){
		return number1 - number2;
	}
};

class CalculatorMulitiple: public AbstractCalculator{
public:
	float getResult(){
		return number1 * number2;
	}
};

void function(){
	//多態使用條件
	//父指針或者引用指向子類對象

	//创建加法计算器
	AbstractCalculator * c = new CalculatorAdd;
	c->number1 = 20;
	c->number2 = 30;
	cout<<c->getResult()<<endl;
	delete c;

	//创建減法计算器
	c = new CalculatorSubstract;
	c->number1 = 20;
	c->number2 = 30;
	cout<<c->getResult()<<endl;
	delete c;

	//创建乘法计算器
	c = new CalculatorSubstract;
	c->number1 = 20;
	c->number2 = 30;
	cout<<c->getResult()<<endl;
	delete c;

};

int main(){
	
	function();

}