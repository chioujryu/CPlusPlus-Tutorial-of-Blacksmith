#include<iostream>
using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son :public Base
{
public:
	int m_D;
};

//利用`Developer Command Prompt for VS 2022`查看對象模型
//跳轉文件路徑，使用 cd
// cl /d1 reportSingleClassLayout <文件名>
void test01()
{
	//父類中所有非靜態成員屬性都會被子類繼承下去
	//父類中私有成員屬性 是被編譯器給隱藏了，因此是訪問不到，但是確實被繼承下去了
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}