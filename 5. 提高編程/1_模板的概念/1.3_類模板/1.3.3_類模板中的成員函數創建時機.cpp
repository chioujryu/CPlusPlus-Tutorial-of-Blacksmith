# include <iostream>
using namespace std;

//類模板中成員函數創建時機


class Person01
{
public:
    void ShowPerson01()
    {
        cout<<"Person01 show"<<endl;
    }

};

class Person02
{
public:
    void ShowPerson02()
    {
        cout<<"Person02 show"<<endl;
    }
};

template<class T>
class MyClass
{
public:
    T obj; 


	//類模板中的成員函數，並不是一開始就創建的，而是在模板調用時再生成

    //類模板中的成員函數
    void function01()
    {
        obj.ShowPerson01();
    }   
    void function02()
    {
        obj.ShowPerson02();
    }
};

void test01()
{
    MyClass<Person01>m;
    m.function01(); 
    //m.function02();   // Person01 不可以調 function02
}

void test02()
{
    MyClass<Person02>m;
    //m.function01();   // Person02 不可以調 function01
    m.function02();
}

int main()
{
    test01();
    test02();
    
    system("pause");

	return 0;
}