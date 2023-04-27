#pragma once //防止頭文件重複包含
#include<iostream>
using namespace std;

class Worker{
public:
    //獲取個人信息
    virtual void showInfo() = 0;

    //獲取部門名稱
    virtual string getDepartmentName()=0;
    
public:
    int m_ID;
    string m_Name;
    int position;
};










