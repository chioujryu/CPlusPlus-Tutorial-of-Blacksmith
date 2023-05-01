#include"boss.h"

Boss::Boss(int m_ID, string m_Name, int position){
    this->m_ID = m_ID;
    this->m_Name = m_Name;
    this->position = position;
};

//獲取個人信息
void Boss::showInfo(){
    cout << "員工編號：" << m_ID 
            << "\t員工姓名：" << m_Name
            << "\t員工部門ID：" << position 
            <<"\t工作責任："<<"給manager工作事務"<< endl;
};  

//獲取部門名稱
string Boss::getDepartmentName(){
    cout<<"5465465"<<endl;

};  