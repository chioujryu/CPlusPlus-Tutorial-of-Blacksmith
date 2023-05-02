#include "manager.h"

Manager::Manager(int m_ID, string m_Name, int position){
    this->m_ID = m_ID;
    this->m_Name = m_Name;
    this->position = position;
};

//獲取個人信息
void Manager::showInfo(){
    cout << "員工編號：" << m_ID 
            << "\t員工姓名：" << m_Name
            << "\t員工部門ID：" << position << endl;
};   

//獲取部門名稱
string Manager::getDepartmentName(){
    cout<<"經理"<<endl;
};  