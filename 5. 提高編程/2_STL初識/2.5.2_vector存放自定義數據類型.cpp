#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>  // 標準算法頭文件

// vector中存放自定義數據類型，並打印輸出
class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

void test01()
{
    vector<Person> v;

    Person p1("孫悟空", 999);
    Person p2("包青天", 31);
    Person p3("柯文哲", 56);
    Person p4("賈伯斯", 56);
    Person p5("馬克祖克伯", 38);

    // 向容器中添加數據
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍歷容器中的數據
    for(vector<Person>::iterator it = v.begin() ; it != v.end() ; it++)
    {
        // (*it) 是 Person 的 地址
        // cout << "姓名：" << (*it).m_name << "\t" << "年齡：" << (*it).m_age << endl;
        cout << "姓名：" << it->m_name << "\t" << "年齡：" << it->m_age << endl;
    }
}

// 存放自訂數據類型 指針
void test02()
{
    vector<Person*> v;  

    Person p1("孫悟空", 999);   
    Person p2("包青天", 31);
    Person p3("柯文哲", 56);
    Person p4("賈伯斯", 56);
    Person p5("馬克祖克伯", 38);

    // 向容器中添加數據
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    // 遍歷容器中的數據
    for(vector<Person *>::iterator it = v.begin() ; it != v.end() ; it++)
    {
        // (*it) 是 Person 指針
        // cout << "姓名：" << (*it)->m_name << "\t" << "年齡：" << (*it)->m_age << endl;
        cout << "姓名：" << (**it).m_name << "\t" << "年齡：" << (**it).m_age << endl;
    }
}

int main()
{
    // test01();
    test02();

    return 0;
}
