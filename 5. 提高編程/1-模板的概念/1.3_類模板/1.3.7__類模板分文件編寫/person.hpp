#pragma once
#include <iostream>
using namespace std;

// ============類模板============
template<typename T1, typename T2>
class Person
{
private:

public:
    Person(T1 name, T2 age);
    void showPerson();

    T1 m_name;
    T2 m_age;
};

// ============實現函數============
//構造函數 類外實現
template<typename T1, typename T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
};

// ============實現函數============
//成員函數 類外實現
template<typename T1, typename T2>
void Person<T1, T2>::showPerson()
{
    cout<<"姓名:"<<m_name<<"\t"<<"年齡:"<<m_age<<endl;
};