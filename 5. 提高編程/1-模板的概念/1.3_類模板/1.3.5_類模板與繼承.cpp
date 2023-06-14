# include <iostream>
using namespace std;
#include <typeinfo> 

//類模板與繼承

template<typename T>
class Base
{

    //成員
    T m;
};

//class Son: public Base  // 錯誤，必須要知道父類中T的類型，才能繼承給子類，因為子類要知道父類的記憶體大小
class Son01: public Base<int>
{

};

void test01()
{
    Son01 s1;
};

//如果想靈活指定父類中T類型，子類也需要變類模板
template <class T1, class T2>
class Son02: public Base<T2>
{
public:
    Son02()
    {
        cout <<"T1的類型為"<< typeid(T1).name() << endl;
		cout <<"T2的類型為"<< typeid(T2).name() << endl;
    }
    T1 obj;
};

void test02()
{
    Son02<int, char> S2;
};


int main()
{
    test02();

	return 0;
}