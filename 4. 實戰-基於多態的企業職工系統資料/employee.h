// #pragma once 
using namespace std;
#include<iostream>
#include"worker.h"

class Employee: public Worker{
public:
    //構造函數
    Employee(int m_ID,string m_Name,int position);

    //獲取個人信息
    virtual void showInfo();  // 這裡不可以用純虛函數，因為在父類已經是純虛函數了

    //獲取部門名稱
    virtual string getDepartmentName();     // 這裡不可以用純虛函數，因為在父類已經是純虛函數了
};

