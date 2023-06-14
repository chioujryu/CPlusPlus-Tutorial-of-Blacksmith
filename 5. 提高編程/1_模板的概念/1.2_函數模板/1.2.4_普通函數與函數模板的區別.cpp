# include <iostream>
using namespace std;

// 普通函數與函數模板區別

//1. 普通函數調用可以發生隱式類型轉換
//2. 函數模板 用自動類型推導，不可以發生隱式類型轉換
//3. 函數模板 用顯示指定類型，可以發生隱式類型轉換



//普通函數
int AddTwoNumber(int a, int b)
{
    return a + b;
}

//函數模板
template<class T>
T AddTwoNumberAnyType(T a, T b)
{
    return a + b;
}

void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    //1. 普通函數調用可以發生隱式類型轉換
    cout<<AddTwoNumber(a,b)<<endl;
    cout<<AddTwoNumber(a,c)<<endl;  // 將字串轉乘ASCII碼, c = 99, a = 97

    cout << AddTwoNumberAnyType(a, b) << endl;

    // 2. 函數模板 用自動類型推導，不可以發生隱式類型轉換
    //cout << AddTwoNumberAnyType(a, c) << endl;    //報錯

    //3. 函數模板 用顯示指定類型，可以發生隱式類型轉換
    cout<<AddTwoNumberAnyType<int>(a,c)<<endl;
}

int main()
{
    test01();
}