#pragma once    //防止頭文件重複包含
#include <iostream> //包含輸入輸出流的頭文件
#include "worker.h"
using namespace std;    //使用標準的命名空間

#include<fstream>
#define all_employees_detail_file_txt "all_employees_detail.txt"

class WorkManager
{
public:
    //構造函數
    WorkManager();

    //展示菜單
    void ShowMenu();

    //退出系統
    void exitSystem();

    //選擇菜單
    void SelectionMenuOption(int op);

    //增加員工
    void AddEmployee();

    //保存文件
    void SaveEmployeeDetail();

    //紀錄文件中的人數
    int m_worker_number_;

    //員工陣列的指針，裡面必須放worker對象指針
    Worker ** m_worker_array_ptr_;  //這是指針的指針

    //判斷文件是否為空
    bool m_file_is_empty_;

    //獲取紀錄文件csv中的人數
    int GetEmployeeNumberFromTXT();

    //初始化員工。從外部檔案導入到程式裡面，初始化程式裡面的員工資料
    void InitEmployee();

    //顯示員工的函數
    void Show_Workers();

    //刪除員工的函數
    void Delete_Workers();

    //判斷員工是否存在，如果存在就返回那個員工在陣列中的位置，如果不存在就返回-1
    int Check_Exist_Worker(int worker_id);

    //修改員工的資訊
    void ModifyWorkerDetail();

    //查找員工，可以按造(id, 姓名, 職位)，來查找
    void SearchWorker();

    //析構函數
    ~WorkManager();
};