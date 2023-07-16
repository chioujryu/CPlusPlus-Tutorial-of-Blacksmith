#include <iostream>
using namespace std;

#include <limits>

#include <iomanip>

#include <typeinfo>


int main(void) {

	//强制使用小数,防止使用科学计数法
    //cout << fixed;

    //控制显示的精度，控制小数点后面的位数。而整数太大时也会使用科学计数法，要输出完整的整数时就可以将下面改成setprecision(0)
    // cout << setprecision(0);

    cout << " *************** 浮點數 *************** "<< endl;
	cout << "float 類型所佔內存空間為： " << sizeof(float) << endl;
    cout << "float 数据类型最大值：" << (numeric_limits<float>::max)() << endl; 
    cout << "float 数据类型最小值：" << (numeric_limits<float>::min)() << endl;

    cout << "" << endl;

	cout << "double 類型所佔內存空間為： " << sizeof(double) << endl;
    cout << "double 数据类型最大值：" << (numeric_limits<double>::max)() << endl; 
    cout << "double 数据类型最小值：" << (numeric_limits<double>::min)() << endl;

    cout << "" << endl;

	cout << "long double 類型所佔內存空間為： " << sizeof(long double) << endl;
    cout << "long double 数据类型最大值：" << (numeric_limits<long double>::max)() << endl; 
    cout << "long double 数据类型最小值：" << (numeric_limits<long double>::min)() << endl;

	cout << "" << endl;

    cout << " *************** 整數 *************** "<< endl;
	cout << "short 類型所佔內存空間為： " << sizeof(short) << endl;
    cout << "short 数据类型最大值：" << (numeric_limits<short>::max)() << endl; 
    cout << "short 数据类型最小值：" << (numeric_limits<short>::min)() << endl;

	cout << "" << endl;

	cout << "unsigned short 類型所佔內存空間為： " << sizeof(unsigned short) << endl;
    cout << "unsigned short 数据类型最大值：" << (numeric_limits<unsigned short>::max)() << endl; 
    cout << "unsigned short 数据类型最小值：" << (numeric_limits<unsigned short>::min)() << endl;

    cout << "" << endl;

	cout << "int 類型所佔內存空間為： " << sizeof(int) << endl;
    cout << "int 数据类型最大值：" << (numeric_limits<int>::max)() << endl; 
    cout << "int 数据类型最小值：" << (numeric_limits<int>::min)() << endl;

    cout << "" << endl;

	cout << "unsigned int 類型所佔內存空間為： " << sizeof(unsigned int) << endl;
    cout << "unsigned int 数据类型最大值：" << (numeric_limits<unsigned int>::max)() << endl; 
    cout << "unsigned int 数据类型最小值：" << (numeric_limits<unsigned int>::min)() << endl;

	cout << "" << endl;

	cout << "long 類型所佔內存空間為： " << sizeof(long) << endl;
    cout << "long 数据类型最大值：" << (numeric_limits<long>::max)() << endl; 
    cout << "long 数据类型最小值：" << (numeric_limits<long>::min)() << endl;

	cout << "" << endl;

	cout << "unsigned long 類型所佔內存空間為： " << sizeof(unsigned long) << endl;
    cout << "unsigned long 数据类型最大值：" << (numeric_limits<unsigned long>::max)() << endl; 
    cout << "unsigned long 数据类型最小值：" << (numeric_limits<unsigned long>::min)() << endl;

	cout << "" << endl;

	cout << "long long 類型所佔內存空間為： " << sizeof(long long) << endl;
    cout << "long long 数据类型最大值：" << (numeric_limits<long long>::max)() << endl; 
    cout << "long long 数据类型最小值：" << (numeric_limits<long long>::min)() << endl;

	cout << "" << endl;

	cout << "unsigned long long 類型所佔內存空間為： " << sizeof(unsigned long long) << endl;
    cout << "unsigned long long 数据类型最大值：" << (numeric_limits<unsigned long long>::max)() << endl; 
    cout << "unsigned long long 数据类型最小值：" << (numeric_limits<unsigned long long>::min)() << endl;

	cout << "\n"<< endl;

	cout << " *************** typedef  *************** "<< endl;
	// 建議用下面方式來定義數據類型，因為這樣程式碼跨平台會比較不會有Bug
	
	cout << "int8_t 類型所佔內存空間為： " << sizeof(int8_t) << endl;
	cout << "int8_t 的型別為： " << typeid(int8_t).name() << endl;

	cout << "" << endl;

	cout << "uint8_t 類型所佔內存空間為： " << sizeof(uint8_t) << endl;
	cout << "uint8_t 的型別為： " << typeid(uint8_t).name() << endl;

	cout << "" << endl;

	cout << "int16_t 類型所佔內存空間為： " << sizeof(int16_t) << endl;
    cout << "int16_t 数据类型最大值：" << (numeric_limits<int16_t>::max)() << endl; 
    cout << "int16_t 数据类型最小值：" << (numeric_limits<int16_t>::min)() << endl;

	cout << "" << endl;

	cout << "uint16_t 類型所佔內存空間為： " << sizeof(uint16_t) << endl;
    cout << "uint16_t 数据类型最大值：" << (numeric_limits<uint16_t>::max)() << endl; 
    cout << "uint16_t 数据类型最小值：" << (numeric_limits<uint16_t>::min)() << endl;

	cout << "" << endl;

	cout << "size_t 類型所佔內存空間為： " << sizeof(size_t) << endl;
    cout << "size_t 数据类型最大值：" << (numeric_limits<size_t>::max)() << endl; 
    cout << "size_t 数据类型最小值：" << (numeric_limits<size_t>::min)() << endl;

	cout << "" << endl;

	cout << "int32_t 類型所佔內存空間為： " << sizeof(int32_t) << endl;
    cout << "int32_t 数据类型最大值：" << (numeric_limits<int32_t>::max)() << endl; 
    cout << "int32_t 数据类型最小值：" << (numeric_limits<int32_t>::min)() << endl;

	cout << "" << endl;

	cout << "uint32_t 類型所佔內存空間為： " << sizeof(uint32_t) << endl;
    cout << "uint32_t 数据类型最大值：" << (numeric_limits<uint32_t>::max)() << endl; 
    cout << "uint32_t 数据类型最小值：" << (numeric_limits<uint32_t>::min)() << endl;

	cout << "" << endl;

	cout << "int64_t 類型所佔內存空間為： " << sizeof(int64_t) << endl;
    cout << "int64_t 数据类型最大值：" << (numeric_limits<int64_t>::max)() << endl; 
    cout << "int64_t 数据类型最小值：" << (numeric_limits<int64_t>::min)() << endl;

	cout << "" << endl;

	cout << "uint64_t 類型所佔內存空間為： " << sizeof(uint64_t) << endl;
    cout << "uint64_t 数据类型最大值：" << (numeric_limits<uint64_t>::max)() << endl; 
    cout << "uint64_t 数据类型最小值：" << (numeric_limits<uint64_t>::min)() << endl;

	cout << "" << endl;

	cout << " *************** char  *************** "<< endl;

	cout << "char 類型所佔內存空間為： " << sizeof(char) << endl;
	cout << "string 類型所佔內存空間為： " << sizeof(string) << endl;

	cout << "" << endl;

	cout << " *************** bool  *************** "<< endl;
    cout<< "bool 類型所佔內存空間為： " <<sizeof(bool)<<endl;
    cout << "bool 数据类型最大值：" << (numeric_limits<bool>::max)() << endl; 
    cout << "bool 数据类型最小值：" << (numeric_limits<bool>::min)() << endl;

	cout << " *************** pointer  *************** "<< endl;
    cout<< "pointer 類型所佔內存空間為： " <<sizeof(void *)<<endl;


}