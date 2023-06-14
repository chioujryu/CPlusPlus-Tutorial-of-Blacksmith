# include <iostream>
using namespace std;
#include <typeinfo> 

#include "myarray.hpp"

void test01()
{
    int capacity = 5;

    // 1. 查看構造函數是否啟用
    MyArray<int>arr01(capacity);
    // 2. 查看拷貝構造函數是否啟用
    MyArray<int>arr02(arr01);
    // 3. 查看 operator= 是否啟用
    MyArray<int>arr03(100);
    arr03 = arr01;

    // 4. 利用尾插法向數組中插入數據
    for (int i = 0; i < capacity ; i++)
    {
        arr01.PuahBack(i);
    }
    
    arr01.PrintArray();
    cout<<"GetCapacity = "<<arr01.GetCapacity()<<endl;  
    cout<<"GetSize = "<<arr01.GetSize()<<endl;


    // 5. 利用尾刪法向數組中刪除數據
    arr01.PopBack();
    cout<<"尾刪後"<<endl; 
    cout<<"GetCapacity = "<<arr01.GetCapacity()<<endl;  
    cout<<"GetSize = "<<arr01.GetSize()<<endl;
};

// 6. 測試自訂數據類型
class Person
{
public:
    Person(){} // 默認構造
    Person(string name, int age) // 有參構造函數
    {
        this->m_age = age;
        this->m_name = name;
    }
    string m_name;
    int m_age;
};

// 7. 設計一個打印 Person 數據類型的函數
void PrintPersonArray(MyArray<Person> & person_array)
{
    for (int i = 0 ; i < person_array.GetSize() ; i++ )
    {
        cout << "姓名：" << person_array[i].m_name << " 年齡： " << person_array[i].m_age << endl;
    }
}

void test02()
{
    // 8. 創建一個 person 的 array
    MyArray<Person> person_arr(10);
    Person p1("孫悟空", 999);
    Person p2("韓信", 20);
    Person p3("流川風", 16);
    Person p4("李佳惠", 24);
    Person p5("趙雲", 30);

    // 9. 將數據插入到數組中
    person_arr.PuahBack(p1);
    person_arr.PuahBack(p2);
    person_arr.PuahBack(p3);
    person_arr.PuahBack(p4);
    person_arr.PuahBack(p5);

    // 10. 打印 Person 數據類型
    PrintPersonArray(person_arr);

	cout << "pArray的大小：" << person_arr.GetSize() << endl;
	cout << "pArray的容量：" << person_arr.GetCapacity() << endl;
}

int main()
{
    test01();
}