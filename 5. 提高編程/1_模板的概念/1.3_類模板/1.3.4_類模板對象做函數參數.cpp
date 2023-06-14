# include <iostream>
using namespace std;
#include <typeinfo> 


//類模板對象做函數參數
template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout<<"姓名:"<<this->m_Name<<"年齡:"<<this->m_Age<<endl;
    }

    T1 m_Name;
    T2 m_Age;

};



//===============1. 指定傳入類型===============
//這是最常用的方式，建議都用這種用法
void PrintPerson01(Person<string, int> & p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int> p("孫悟空", 100);
    PrintPerson01(p);
}

//===============2. 參數模板化===============
template<class T1, class T2>
void PrintPerson02(Person<T1, T2> & p)
{
    p.showPerson();
    cout<<"T1 的類型為:"<< typeid(T1).name()<<endl;
    cout<<"T2 的類型為:"<< typeid(T2).name()<<endl;
}
void test02()
{
    Person<string, int> p("豬八戒", 90);
    PrintPerson02(p);
}

//===============3. 整個類模板化===============
template<class T>
void PrintPerson03(T & p)
{
    p.showPerson();
    cout<<"T的數據類型為:"<<typeid(T).name()<<endl;
}
void test03()
{
    Person<string, int> p("唐僧", 30);
    PrintPerson03(p);
}


int main()
{
    test01();
    test02();
    test03();

	return 0;
}