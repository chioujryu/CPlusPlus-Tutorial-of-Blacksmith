#pragma once
#include<iostream>
#include"worker.h"

//老闆類
class Boss: public Worker{
public:
    //構造函數
    Boss(int m_ID, string m_Name, int position);
    //獲取個人信息
    virtual void showInfo(); 
    //獲取部門名稱
    virtual string getDepartmentName(); 
};

