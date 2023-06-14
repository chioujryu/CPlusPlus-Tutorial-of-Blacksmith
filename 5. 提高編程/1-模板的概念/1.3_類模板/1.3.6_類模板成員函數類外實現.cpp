# include <iostream>
using namespace std;
#include <typeinfo> 

//類模板與繼承

// ============類模板============
template<typename T1, typename T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void showPerson();

    T1 m_name;
    T2 m_age;
};

// ============構造函數的類外實現============
template<typename T1, typename T2>
//Person::Person(T1 name, T2 age)   // 這是普通構造函數的類外實現，我們要類模板的普通構造函數類外實現
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
};

// ============成員函數的類外實現============
template<typename T1, typename T2>
void Person<T1, T2>::showPerson()
{
    cout<<"姓名:"<<this->m_name<<"\t"<<"年齡"<<this->m_age<<endl;
};

// ============類模板調用============
void test01()
{
    Person<string, int> p("孫悟空", 100);
    p.showPerson();
}

// ============main函數============
int main()
{
    test01();
	return 0;
}