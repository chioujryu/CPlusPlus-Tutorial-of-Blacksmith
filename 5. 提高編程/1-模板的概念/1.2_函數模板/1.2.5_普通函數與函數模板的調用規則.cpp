# include <iostream>
using namespace std;

// 普通函數與函數模板的調用規則

//1. 如果函數模板與普通函數都可以調用，優先調用普通函數
//2. 可以通過空模板參數列表，強制調用 函數模板
//3. 函數模板可以發生函數重載
//4. 如果函數模板可以產生更好的匹配，優先調用函數模板

void MyPrint(int a, int b)
{
    cout<<"調用的是普通函數"<<endl;
}

template<class T>
void MyPrint(T a, T b)
{
    cout<<"調用的是模板"<<endl;
}

template<class T>
void MyPrint(T a, T b, T c)
{
    cout<<"調用的是重載的模板"<<endl;
}

void test01()
{
    int a = 10;
    int b = 20;

    //1. 如果函數模板與普通函數都可以調用，優先調用普通函數
    MyPrint(a, b);

    //2. 可以通過空模板參數列表，強制調用 函數模板
    MyPrint<>(a, b);

    //3. 函數模板可以發生函數重載
    MyPrint<>(a, b, 100);

    //4. 如果函數模板可以產生更好的匹配，優先調用函數模板
    //先調用函數模板是因為，調用普通函數還必須要把字符串轉換成整數，所以系統優先調用函數模板
    const char c1[] = "a";
    const char c2[] = "b";
    MyPrint(c1, c2);  
}

int main()
{
    test01();
}