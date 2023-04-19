#include<iostream>
using namespace std;

class Base1
{
public: 
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//公共继承
class Son1 :public Base1
{
public:
	void func()
	{
		m_A; //父類中是 public 權限成員，到子類中依然是 public 權限
		m_B; //父類中是 protected 權限成員，到子類中依然是 protected 權限
		//m_C; //不可访问
	}
};

void myClass()
{
	Son1 s1;
	s1.m_A; //其他类只能访问到公共权限
	//s1.m_B;	//m_B是 protected 權限，所以類外訪問不到
}

//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2:protected Base2
{
public:
	void func()
	{
		m_A; //父類中的 public 成員，子類中也會變成 protected 权限
		m_B; //父類中的 protected 成員，子類中也會變成 protected 权限
		//m_C; //父類中的 private 成員，子類中訪問不到
	}
};

void myClass2()
{
	Son2 s;
	//s.m_A; //上 Son2 中 m_A 是 protected 权限，所以類外無法訪問
}

//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son3:private Base3
{
public:
	void func()
	{
		m_A; //父類中的 public 成員到子類中變成 private 成員
		m_B; //父類中的 protected 成員到子類中變成 private 成員
		//m_C; //父類中 private 成員訪問不到
	}
};

void myClass3()
{
	Son3 s;
	//s.m_A; // Son3 中 m_A 是 private 成員，所以類外無法訪問
}

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
		//m_A;
		//m_B;
		//m_C;
	}
};

int main(){

	myClass();

	return 0;

};