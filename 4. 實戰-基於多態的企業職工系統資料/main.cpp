#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

int main(){

//     //測試程式碼
//     Worker * worker = nullptr;
//     worker = new Boss(1,"大帥哥",5);
//     worker->showInfo();
//     cout<<worker<<endl;
//     delete worker;
    
//     Worker * worker1 = nullptr;
//     worker1 = new Boss(2,"大美女",5);
//     worker->showInfo();
//     cout<<worker<<endl;
//     delete worker;
// }


    
    //實例化管理對象
    WorkManager workerManager;

    int choice = 0; //用來存儲用戶的選項
    while(true){

        //展示菜單
        workerManager.ShowMenu();
        cout<<"請輸入你的選擇"<<endl;
        cin>>choice;    //接受用戶的選項
        switch (choice)
        {
        case 0: //退出管理程式
            workerManager.exitSystem();
            break;
        case 1: //增加職工信息
            workerManager.AddEmployee();
            break;
        case 2: //顯示職工信息
            workerManager.Show_Workers();
            break;
        case 3: //刪除離職職工
        {
            //測試用的程式碼，先隱藏掉，你也可以再打開它
            // int result = workerManager.Check_Exist_Worker(1);
            // if (result == -1)
            // {
            //     cout << "員工不存在" << endl;
            // }
            // else
            // {
            //     cout << "員工存在" << endl;    
            // }

            workerManager.Delete_Workers();
            break;
        }
        case 4: //修改職工信息
            workerManager.ModifyWorkerDetail();
            break;
        case 5: //查找職工信息
            workerManager.SearchWorker();
            break;
        case 6: //按造編號排序
            workerManager.SortWorker();
            break;
        case 7: //清空所有文檔
            workerManager.CleanFile();
            break;
        default:
            cout<<"輸入錯誤，請重新輸入"<<endl;
            system("cls");
            break;
        }

    }

    

    system("pause");
}
