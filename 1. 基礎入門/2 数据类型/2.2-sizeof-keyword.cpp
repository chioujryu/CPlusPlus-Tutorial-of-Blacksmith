#include <iostream>
using namespace std;

int main() {

	cout << "short 類型所佔內存空間為： " << sizeof(short) << endl;

	cout << "int 類型所佔內存空間為： " << sizeof(int) << endl;

	cout << "long 類型所佔內存空間為： " << sizeof(long) << endl;

	cout << "long long 類型所佔內存空間為： " << sizeof(long long) << endl;

	cout << "\n"<< endl;

	cout << "unsigned short 類型所佔內存空間為： " << sizeof(unsigned short) << endl;

	cout << "unsigned int 類型所佔內存空間為： " << sizeof(unsigned int) << endl;

	cout << "unsigned long 類型所佔內存空間為： " << sizeof(unsigned long) << endl;

	cout << "unsigned long long 類型所佔內存空間為： " << sizeof(unsigned long long) << endl;

	// 建議用下面方式來定義數據類型，因為這樣程式碼跨平台會比較不會有Bug

	cout << "\n"<< endl;

	cout << "int8_t 類型所佔內存空間為： " << sizeof(int8_t) << endl;

	cout << "uint8_t 類型所佔內存空間為： " << sizeof(uint8_t) << endl;

	cout << "int16_t 類型所佔內存空間為： " << sizeof(int16_t) << endl;

	cout << "uint16_t 類型所佔內存空間為： " << sizeof(uint16_t) << endl;

	cout << "int32_t 類型所佔內存空間為： " << sizeof(int32_t) << endl;

	cout << "uint32_t 類型所佔內存空間為： " << sizeof(uint32_t) << endl;

	cout << "int64_t 類型所佔內存空間為： " << sizeof(int64_t) << endl;

	cout << "uint64_t 類型所佔內存空間為： " << sizeof(uint64_t) << endl;

	return 0;
}