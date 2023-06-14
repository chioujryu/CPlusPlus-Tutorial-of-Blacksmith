# include <iostream>
using namespace std;

//類模板
template <typename Nametype, typename AgeType>
class Person
{
public:
    Person(Nametype name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void ShowPerson()
    {
        cout<<"name = "<<this->m_Name<<"\t"<<"age = "<<this->m_Age<<endl;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    // 指定NameType 爲string類型，AgeType 爲 int類型
    Person<string, int> p1("孫悟空", 999);
    p1.ShowPerson();
}

int main()
{
    test01();
}