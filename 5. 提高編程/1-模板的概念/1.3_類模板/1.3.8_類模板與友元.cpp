# include <iostream>
using namespace std;
#include <typeinfo> 

//通過全局函數打印Person的信息

// 7. 提前讓編譯器知道Person的存在，因為在 步驟<6> 使用到了Person
// 全局函數配合友元  類外實現 - 先做函數模板聲明，下方在做函數模板定義，在做友元
template<class T1, class T2> 
class Person;

// 6. 全局函數 類外實現
// 如果聲明瞭函數模板，可以將實現寫到後面，否則需要將實現體寫到類的前面讓編譯器提前看到
template<typename T1, typename T2>
void PrintPerson02(Person<T1, T2> p)
{
    cout<<"類外實現------"<<"姓名:"<<p.m_name<<"\t"<<"年齡"<<p.m_age<<endl;
}

// 1. 定義類模板
template<typename T1, typename T2>
class Person
{
    // 2. 全局函數 類內實現
    friend void PrintPerson01(Person<T1, T2> p)
    {
        cout<<"姓名:"<<p.m_name<<"\t"<<"年齡"<<p.m_age<<endl;
    }

    // 3. 全局函數 類外實現 定義
    // friend void PrintPerson02(Person<T1, T2> p);  //這是普通函數的聲明
    // 加
    // 如果全局函數 是類外實現，需要讓編譯器提前知道這個函數的存在
    friend void PrintPerson02<>(Person<T1, T2> p);  //這是函數模板的聲明

public:
    // 4. 定義構造函數
    Person(T1 name, T2 age);

private:
    T1 m_name;
    T2 m_age;
};

// 5. 構造函數的類外實現
template<typename T1, typename T2>
//Person::Person(T1 name, T2 age)   // 這是普通構造函數的類外實現，我們要類模板的普通構造函數類外實現
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
};


// 8. 全局函數在類內實現
void test01()
{
    Person<string, int> p("孫悟空", 100);
    PrintPerson01(p);
}

// 9. 全局函數在類外實現
void test02()
{
    Person<string, int> p("孫悟空", 100);
    PrintPerson02(p);
}



// ============main函數============
int main()
{
    test01();
    test02();
	return 0;
}