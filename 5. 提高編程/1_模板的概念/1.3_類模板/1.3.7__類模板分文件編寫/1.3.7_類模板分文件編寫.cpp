// 類模板分文件編寫

# include <iostream>
#include <typeinfo> 
using namespace std;

// ============第一種解決方式============
// 解決方式:直接包含原文件
// 編譯方式: g++ -o main 1.3.7_類模板分文件編寫.cpp person.cpp
#include "person.cpp"


// ============第二種解決方式============
// 解決方式:將 .h 和 .cpp中的內容寫到一起，將後綴名改為 .hpp文件
// 編譯方式: g++ -o main 1.3.7_類模板分文件編寫.cpp
#include "person.hpp"


void test01()
{
    Person<string, int> p("李多惠", 24);
    p.showPerson();
}


// ============main函數============
int main()
{
    test01();
	return 0;
}