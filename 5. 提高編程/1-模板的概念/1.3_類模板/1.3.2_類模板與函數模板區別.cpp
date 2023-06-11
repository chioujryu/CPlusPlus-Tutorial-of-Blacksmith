# include <iostream>
using namespace std;

//類模板與函數模板區別主要有兩點
//1. 類模板沒有自動類型推導的使用方式
//2. 類模板在模板參數列表中可以有默認參數

//類模板與函數模板的區別
template <typename NameType, typename AgeType = int>
class Person
{
public:
    Person (NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void ShowPerson()
    {
        cout<<"name = "<<this->m_name<<"\t"<<"age = "<<this->m_age<<endl;
    }

    string m_name;
    int m_age;
};


//1. 類模板沒有自動類型推導的使用方式
void test01()
{
    //Person p("孫悟空", 1000); // 錯誤，無法自動推導數據類型
    Person<string, int> p("孫悟空", 1000);  // 正確，只能用顯示指定類型
    p.ShowPerson();
}

//2. 類模板在模板參數列表中可以有默認參數
void test02()
{
    //只需指定 string 類型，因為 int 已經在 Person 類裡面是默認類型了
    Person<string> p("孫悟空", 1000);  // 正確
    p.ShowPerson();
}

int main()
{
    test01();
    test02();
}