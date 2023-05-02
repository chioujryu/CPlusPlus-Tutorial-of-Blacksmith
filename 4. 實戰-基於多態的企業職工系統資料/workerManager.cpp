#include"workerManager.h"
#include <iostream> 	//導入輸入輸出流頭文件
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;    //使用標準的命名空間

//構造函數 初始化
WorkManager::WorkManager(){

	//1. 文件不存在
	ifstream ifs;
	ifs.open(all_employees_detail_file_txt,ios::in);

	if (!ifs.is_open()){
		cout<<"員工資料不存在"<<endl;

		//初始化屬性
		//初始化員工人數
		this->m_worker_number_ = 0;
		//初始化陣列指針
		this->m_worker_array_ptr_ = nullptr;
		//將 m_file_is_empty_ 改成 true
		this->m_file_is_empty_ = true;
		//關閉文件
		ifs.close();
		return;
	}

	//2. 文件存在，但裡面為空白的
	char ch;
	ifs>>ch;
	if(ifs.eof())
	{
		cout<<"已有員工資料 txt 文件，但裡面為空白的"<<endl;
		//初始化屬性
		//初始化員工人數
		this->m_worker_number_ = 0;
		//初始化陣列指針
		this->m_worker_array_ptr_ = nullptr;
		//將 m_file_is_empty_ 改成 true
		this->m_file_is_empty_ = true;
		//關閉文件
		ifs.close();
		return;
	}

	//3. 文件存在，裡面也有員工資料
	char ch_2;
	ifs>>ch_2;
	if(!ifs.eof())
	{
		//將 m_file_is_empty_ 改成 false
		this->m_file_is_empty_ = false;

		cout<<"已有員工資料 txt 文件"<<endl;

		int employee_number_in_txt = this->GetEmployeeNumberFromTXT();
		cout<<"目前員工資料裡面有："<<employee_number_in_txt<<"個員工"<<endl;

		//初始化屬性
		//初始化員工人數
		this->m_worker_number_ = employee_number_in_txt;

		//開闢空間
		this->m_worker_array_ptr_ = new Worker * [this->m_worker_number_];
		
		//將文件中的數據存到陣列中
		this->InitEmployee();

        //測試用的程式碼，可以註釋掉，你也可以將它打開
		// for(int i=0;i<this->m_worker_number_;i++){
		// 	cout<<"員工編號："<<this->m_worker_array_ptr_[i]->m_ID
		// 		<<"\t員工姓名"<<this->m_worker_array_ptr_[i]->m_Name
		// 		<<"\t員工職位"<<this->m_worker_array_ptr_[i]->position<<endl;
		// }
	}

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

//離開系統
void WorkManager::exitSystem(){
	cout<<"歡迎下次再次使用"<<endl;
	system("pause");
	exit(0);
}

//選擇菜單
void WorkManager::SelectionMenuOption(int op){
	

};

//增加員工
void WorkManager::AddEmployee(){
	
	//設定要增加的員工數量
	cout<<"請輸入想增加的員工數量"<<endl;
	int add_employee_number = 0;	
	cin>>add_employee_number;


	// 如果你輸入的員工數量大於 0 的話，
	if(add_employee_number > 0){
		//添加
		//計算新空間大小
		// 新空間大小 = 原來的紀錄人數 + 新增人數
		int new_employee_number = this->m_worker_number_ + add_employee_number;	

		//開闢新空間
		//這個陣列的每個元素都是一個指向 Worker 類別的指標
		//總的來說，這段程式碼創建了一個可以存放多個 Worker 對象指標的陣列，並將其陣列大小指定為 new_employee_number。
		//更簡單來是一次建立了好幾個 Worker 對象指標
		Worker ** new_employee_array = new Worker*[new_employee_number];		

		//將原空間下內容拷貝到新空間下
		//意味著如果 m_worker_array_ptr_ 已經有員工了
		//那新增的員工會再從後面加上去
		if (this->m_worker_array_ptr_ != nullptr){
			for(int i = 0; i < this->m_worker_number_; i++){
				new_employee_array[i] = this->m_worker_array_ptr_[i];
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
			new_employee_array[this->m_worker_number_ + i] = worker;
		};

		//釋放原有空間
		//delete[]用作於是放陣列
		delete[] this->m_worker_array_ptr_;

		//更改新陣列的指向
		this->m_worker_array_ptr_ = new_employee_array;

		//更新新的員工人數
		this->m_worker_number_ = new_employee_number;

		//判斷員工資料 csv 現在裡面不為空
		this->m_file_is_empty_ = false;

		//保存員工資料到文件中
		this->SaveEmployeeDetail();


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

//保存文件
void WorkManager::SaveEmployeeDetail(){
	ofstream ofs;
	ofs.open(all_employees_detail_file_txt,ios::out);

	//將每個人的數據寫入到文件中
	for(int i = 0; i < this->m_worker_number_; i++)
	{
		ofs<<this->m_worker_array_ptr_[i]->m_ID<<" "
        	<<this->m_worker_array_ptr_[i]->m_Name<<" "
        	<<this->m_worker_array_ptr_[i]->position<<endl;
	}
	//關閉文件
	ofs.close();
}

//獲取現在在 txt 檔裡面的員工人數
int WorkManager::GetEmployeeNumberFromTXT(){

	ifstream ifs;
	ifs.open(all_employees_detail_file_txt,ios::in);

	int id;
	string name;
	int position;

	//紀錄 csv 裡面的人數用的變數
	int employee_number = 0;

	while(ifs>>id && ifs>>name && ifs>>position){
		employee_number++;
	};

	ifs.close();
	return employee_number;
}

//初始化員工。從外部檔案導入到程式裡面，初始化程式裡面的員工資料
void WorkManager::InitEmployee(){
	ifstream ifs;	//創建輸出入流對象
	ifs.open(all_employees_detail_file_txt,ios::in);	//讀取數據

    int m_ID;
    string m_Name;
    int position;

	int index = 0;
	//您需要在循環之前定義它們的作用域。這意味著您需要在循環之前聲明這些指針，
	//並將它們初始化為nullptr。然後在循環中分配內存給這些指針並使用它們，直到循環結束。
	Worker * worker = nullptr;

	while(ifs >> m_ID && ifs >> m_Name && ifs >> position){
		if(position == 1){	//普通員工
			worker = new Employee(m_ID,m_Name,position);
		}
		else if(position == 2){	//經理
			worker = new Manager(m_ID,m_Name,position);
		}
		else if(position == 3){	//老闆
			worker = new Boss(m_ID,m_Name,position);
		}

		this->m_worker_array_ptr_[index] = worker;
		index++;
	};

	ifs.close();	//關閉文件
};

//顯示員工的函數
void WorkManager::Show_Workers(){
	//判斷文件是否為空
	if(this->m_file_is_empty_){
        cout<<"員工資料 csv 目前裡面為空"<<endl;
    }
	else{
		for(int i = 0 ; i < m_worker_number_ ; i++){
			//利用多態調用程序接口
			this->m_worker_array_ptr_[i]->showInfo();
		}
	}
	//按任意鍵清理屏幕
	system("pause");
	system("cls");
};

//刪除員工的函數
void WorkManager::Delete_Workers(){
	if(this->m_file_is_empty_)
	{
		cout<<"員工資料 csv 裡面為空，所以沒東西可以刪除"<<endl;
	}
	else
	{
		cout<<"請輸入想要刪除的員工編號"<<endl;
		int id;
		cin>>id;

		// Check_Exist_Worker()函數用法
		// 如果此id有人，就會返回id。如果沒有人，就會返回-1
		int index = this->Check_Exist_Worker(id);
		if(index != -1)	// 說明員工存在，並且刪除掉 index 位置上的員工
		{
			
			//數據前移
			for(int i = 0; i < this->m_worker_number_ - 1; i++)
            {
                this->m_worker_array_ptr_[i] = this->m_worker_array_ptr_[i + 1];
            };

			//由於刪除了一個人，所以員工總人數要減 1
			this->m_worker_number_--;	

			//數據同步到文件中
			this->SaveEmployeeDetail();
		}
		
		else
		{
			cout<<"刪除失敗,沒有此id"<<endl;
		}
	}

	//按任意鍵清理屏幕
	system("pause");
    system("cls");

};

//判斷員工是否存在，如果存在就返回那個員工在陣列中的位置，如果不存在就返回-1
int WorkManager::Check_Exist_Worker(int worker_id){

	int index = -1;
	for(int i = 0 ; i < m_worker_number_ ; i++){
		if (this->m_worker_array_ptr_[i]->m_ID == worker_id){
			//找到員工
			index = i;
            break;
		}
	}
	return index;
};

// 修改員工的資料
void WorkManager::ModifyWorkerDetail(){
	if(this->m_file_is_empty_)
	{
		cout<<"員工資料 csv 裡面為空，所以沒任何員工資訊可以修改"<<endl;
	}
	else
	{
		cout<<"你想要修改的員工是誰，請輸入他的ID"<<endl;
		int id;
		cin>>id;
		// 如果此ID有人的話，就會返回那個 ID 的陣列 index
		// 如果那個ID沒有人的話，就會返回 -1
		int index = this->Check_Exist_Worker(id);	
		delete this->m_worker_array_ptr_[index];

		if(index != -1)    // 有找到此員工
        {

            cout<<"有找到此員工，請輸入"<<endl;

			cout<<"你要新增的新 ID 為"<<endl;
            int new_id;
			cin>>new_id;

			cout<<"你要新增的新名字為"<<endl;
            string new_name;
			cin>>new_name;

			cout<<"你要新增的新職位為"<<endl;
			cout<<"1. 普通員工"<<endl;
			cout<<"2. 經理"<<endl;
			cout<<"3. 老闆"<<endl;
            int position;
			cin>>position;

			Worker * worker = nullptr;

			switch (position)
			{
			case 1:
				worker = new Employee(new_id,new_name,position);
				break;
			case 2:
				worker = new Manager(new_id,new_name,position);
				break;
			case 3:
				worker = new Boss(new_id,new_name,position);
				break;
			default:
				break;
			}

			this->m_worker_array_ptr_[index] = worker;	// ?Nworker??H??????R?????????

			cout<<"success"<<endl;

			// 將所有員工資訊存進TXT檔案裡面
			this->SaveEmployeeDetail();

		}
		else
		{
			cout<<"查無此員工"<<endl;
		}
	}
	//清理螢幕的資訊
	system("pause");
	system("cls");
};

void WorkManager::SearchWorker(){
	if (this->m_file_is_empty_)
	{
		cout<<"員工資料 csv 裡面為空，所以沒任何員工資訊可以查詢"<<endl;
	}
	else
	{
		cout<<"請輸入要查詢的方式"<<endl;
		cout<<"1. 用ID查詢"<<endl;
		cout<<"2. 用姓名查詢"<<endl;

		int selection;
		cin>>selection;

		if (selection == 1)
		{
			cout<<"請輸入要查找的ID為"<<endl;
			int id;
			cin>>id;
			int index = Check_Exist_Worker(id);
			if(index != -1)
			{
				this->m_worker_array_ptr_[index]->showInfo();
			}
			else
			{
				cout<<"查無此人"<<endl;
			}
		}
		else if (selection == 2)
		{
			cout<<"請輸入你要查找的姓名"<<endl;
			string name;
			cin >> name;
			bool flag = false;	// 如果 flag 為 false 代表沒有找到人
			for (int i = 0 ; i <  m_worker_number_ ; i++)
			{
				if (this->m_worker_array_ptr_[i]->m_Name == name)
				{
					this->m_worker_array_ptr_[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查無此人" << endl;
			}
		}
		else
		{
			cout<<"輸入錯誤"<<endl;
		}
	}
};


WorkManager::~WorkManager(){
	if(this->m_worker_array_ptr_!= nullptr){
		delete[] this->m_worker_array_ptr_;
	}
};

