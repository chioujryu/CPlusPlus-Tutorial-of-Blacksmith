#include<iostream>
using namespace std;

//處理器
class CPU{
public:
	virtual void calculate() = 0;
};
//顯示卡
class GPU{
public:
	virtual void display() = 0;
};
//記憶體
class RAM{
public:
	virtual void storage() = 0;
};

class Computer{
public:
	Computer(CPU * cpu, GPU * gpu, RAM * ram){
		this->cpu = cpu;
		this->gpu = gpu;
		this->ram = ram;
	};

	void Work(){
		this->cpu->calculate();
		this->gpu->display();
		this->ram->storage();
	};

	//提供析構函數釋放三個零件的指針
	virtual ~Computer(){
		//釋放cpu零件
		if (cpu != NULL){
			delete cpu;
			//cpu = NULL;
			cout<<"cpu記憶體已經被釋放"<<endl;
		}
		//釋放gpu零件
		if (gpu != NULL){
			delete gpu;
			//gpu = NULL;
			cout<<"gpu記憶體已經被釋放"<<endl;
		}
		//釋放ram零件
		if (ram != NULL){
			delete ram;
			//ram = NULL;
			cout<<"ram記憶體已經被釋放"<<endl;
		}
	}
private:
	CPU * cpu;
	GPU * gpu;
	RAM * ram;
};

//Intel零件
class IntelCPU: public CPU{
	virtual void calculate(){
		cout << "Intel的CPU開始運作了" << endl;
	}
};

class IntelGPU: public GPU{
	virtual void display(){
		cout << "Intel的GPU開始運作了" << endl;
	}
};

class IntelRAM: public RAM{
	virtual void storage(){
		cout << "Intel的RAM開始運作了" << endl;
	}
};

//Lenovo零件
class LenovoCPU: public CPU{
	virtual void calculate(){
		cout << "Lenovo的CPU開始運作了" << endl;
	}
};

class LenovoGPU: public GPU{
	virtual void display(){
		cout << "Lenovo的GPU開始運作了" << endl;
	}
};

class LenovoRAM: public RAM{
	virtual void storage(){
		cout << "Lenovo的RAM開始運作了" << endl;
	}
};

void Work(){

	//電腦零件宣告
	CPU * Intelcpu = new IntelCPU;
	GPU * Intelgpu = new IntelGPU;
	RAM * Intelram = new IntelRAM;
	CPU * Lenovocpu = new LenovoCPU;
	GPU * Lenovogpu = new LenovoGPU;
	RAM * Lenovoram = new LenovoRAM;

	//第一台電腦組裝即開始運作
	Computer * intel_computer = new Computer(Intelcpu,Intelgpu,Intelram);
	intel_computer->Work();
	delete intel_computer;
	cout<<"已經釋放掉intel_computer指針"<<endl;

	//第二台電腦組裝即開始運作
	Computer * Levon_computer = new Computer(Intelcpu,Lenovogpu,Intelram);
	Levon_computer->Work();
	delete Levon_computer;
	cout<<"已經釋放掉Levon_computer指針"<<endl;

};


int main(){

	Work();
	
	return 0;

};