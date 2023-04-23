#include<iostream>
using namespace std;

//飲品類
class Drinking{
public:
	virtual void boil() = 0;	//煮水
	virtual void brew() = 0;	//沖泡
	virtual void pourIntoWater() = 0;	//倒水
	virtual void addSomeSeasoning() = 0;	//加調味料

	//執行所有函數
	void implement(){
		boil();
		brew();
		pourIntoWater();
		addSomeSeasoning();
	};
};

//咖啡類
class Coffee: public Drinking{
	virtual void boil(){
		cout<<"煮水"<<endl;
	}
	virtual void brew(){
		cout<<"沖泡咖啡"<<endl;
	}
	virtual void pourIntoWater(){
		cout<<"倒入杯中"<<endl;
	}
	virtual void addSomeSeasoning(){
		cout<<"加入奶精還有糖"<<endl;
	}
};

//茶類
class Tea: public Drinking{
	virtual void boil(){
		cout<<"煮水"<<endl;
	}
	virtual void brew(){
		cout<<"沖泡茶葉"<<endl;
	}
	virtual void pourIntoWater(){
		cout<<"倒入杯中"<<endl;
	}
	virtual void addSomeSeasoning(){
		cout<<"加檸檬"<<endl;
	}
};

//製作飲品
void buildDrink(Drinking * drink){
	drink->implement();
	delete drink;	// 釋放記憶體
}

//製作咖啡
void buildCoffee(){
	buildDrink(new Coffee);
};

//製作茶
void buildTea(){
	buildDrink(new Tea);
};



int main(){

	buildCoffee();
	buildTea();
	
}