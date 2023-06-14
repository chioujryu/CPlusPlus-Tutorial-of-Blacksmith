# include <iostream>
using namespace std;

// 模板的侷限性
// 模板並不是萬能的，有些特定數據類型，需要用具體化方式作特殊實現


class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    
    //姓名
    string m_name;
    //年齡
    int m_age;
};


template <typename T>
bool MyCompare(T & a, T & b)
{
    if(a == b) return true;
    else return false;
}

//利用具體化Person版本實現代碼，具體化優先調用
template<> bool MyCompare(Person & p1, Person & p2)
{
    if(p1.m_name == p2.m_name && p1.m_age == p2.m_age)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void test01()
{
    int a = 10;
    int b = 20;

    bool ret = MyCompare(a,b);
    if (ret == true)
    {
        cout<<"a == b"<<endl;   
    }
    else
    {
        cout<<"a != b"<<endl;
    }
}

void test02()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);

    bool ret = MyCompare(p1, p2);
    if (ret == true)
    {
        cout<<"p1 == p2"<<endl;   
    }
    else
    {
        cout<<"p1 != p2"<<endl;
    }
}

int main()
{
    test01();
    test02();
}