//#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class Manager: public Worker{
public:
    Manager(int m_ID, string m_name, int position);
    //獲取個人信息
    virtual void showInfo();   
    //獲取部門名稱
    virtual string getDepartmentName();  
};
