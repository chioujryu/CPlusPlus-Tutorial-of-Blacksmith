#pragma once    //防止頭文件重複包含
#include <iostream> //包含輸入輸出流的頭文件
#include "worker.h"
using namespace std;    //使用標準的命名空間

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

    //紀錄文件中的人數
    int m_employee_number_;

    //員工陣列的指針
    Worker ** m_employee_array_;  //這是指針的指針

    //析構函數
    ~WorkManager();
};