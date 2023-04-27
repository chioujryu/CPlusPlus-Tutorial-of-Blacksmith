#include"workerManager.h"
#include <iostream> //包含輸入輸出流的頭文件
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;    //使用標準的命名空間

WorkManager::WorkManager(){
	this->m_employee_number_ = 0;
	this->m_employee_array_ = nullptr;
};

//展示菜單
void  WorkManager::ShowMenu(){
	cout << "********************************************" << endl;
	cout << "*********  歡迎使用職工管理系統！ **********" << endl;
	cout << "*************  0.退出管理程式  *************" << endl;
	cout << "*************  1.增加職工信息  *************" << endl;
	cout << "*************  2.顯示職工信息  *************" << endl;
	cout << "*************  3.刪除離職職工  *************" << endl;
	cout << "*************  4.修改職工信息  *************" << endl;
	cout << "*************  5.查找職工信息  *************" << endl;
	cout << "*************  6.按造編號排序  *************" << endl;
	cout << "*************  7.清空所有文檔  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
};

void WorkManager::exitSystem(){
	cout<<"歡迎下次再次使用"<<endl;
	system("pause");
	exit(0);
}

//選擇菜單
void WorkManager::SelectionMenuOption(int op){
	

};

void WorkManager::AddEmployee(){
	
	//設定要增加的員工數量
	cout<<"請輸入想增加的員工數量"<<endl;
	int add_employee_number = 0;	
	cin>>add_employee_number;


	// 如果你輸入的員工數量大於 0 的話，
	if(add_employee_number > 0){
		//添加
		//計算新空間大小
		int new_employee_number = this->m_employee_number_ + add_employee_number;	// 新空間大小 = 原來的紀錄人數 + 新增人數

		//開闢新空間
		//這個陣列的每個元素都是一個指向 Worker 類別的指標
		//總的來說，這段程式碼創建了一個可以存放多個 Worker 對象指標的陣列，並將其陣列大小指定為 new_employee_number。
		//更簡單來是一次建立了好幾個 Worker 對象指標
		Worker ** new_employee_array = new Worker*[new_employee_number];		

		//將原空間下內容拷貝到新空間下
		//意味著如果 m_employee_array_ 已經有員工了
		//那新增的員工會再從後面加上去
		if (this->m_employee_array_ != nullptr){
			for(int i = 0; i < this->m_employee_number_; i++){
				new_employee_array[i] = this->m_employee_array_[i];
			}
		}

		//批量添加新數據
		for(int i = 0; i < add_employee_number; i++){
			int id ; //員工編號
			string name; //員工姓名
			int positionSelection; //選擇職位

			cout<<"請輸入員工ID"<<endl;
			cin>>id;

			cout<<"請輸入員工姓名"<<endl;
			cin>>name;

			cout<<"請選擇職位"<<endl;
			cout<<"1. 普通員工"<<endl;
			cout<<"2. 經理"<<endl;
			cout<<"3. 老闆"<<endl;
            cin>>positionSelection;


			Worker * worker = nullptr;
			switch (positionSelection)
			{
			case 1:  //普通員工
			    worker = new Employee(id,name,1);
				break;
			case 2:  //經理
			    worker = new Manager(id,name,2);
			    break;
			case 3:  //老闆
			    worker = new Boss(id,name,3);
				break;
			default:
                break;
			}

			//將創建員工，保存到數組中
			new_employee_array[this->m_employee_number_ + i] = worker;
		};

		//釋放原有空間
		//delete[]用作於是放陣列
		delete[] this->m_employee_array_;

		//更改新陣列的指向
		this->m_employee_array_ = new_employee_array;

		//更新新的員工人數
		this->m_employee_number_ = new_employee_number;

		//成功添加後，保存到文件中


		//顯示添加成功
		cout<<"已經成功添加"<<add_employee_number<<"名新員工！！"<<endl;


	}
	else
	{
		cout<<"輸入錯誤，請重新輸入"<<endl;
	}
	//按任意鍵後，清理螢幕
	system("pause");
	system("cls");


};



WorkManager::~WorkManager(){
    
};

