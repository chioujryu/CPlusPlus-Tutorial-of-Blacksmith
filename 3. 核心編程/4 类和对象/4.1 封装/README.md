# C++核心编程

本阶段主要针对C++==面向对象==编程技术做详细讲解，探讨C++中的核心和精髓。

## **4** 类和对象


C++面向对象的三大特性为：==封装、继承、多态==



C++认为==万事万物都皆为对象==，对象上有其属性和行为



**例如：**

​	人可以作为对象，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、吃饭、唱歌...

​	车也可以作为对象，属性有轮胎、方向盘、车灯...,行为有载人、放音乐、放空调...

​	具有==相同性质的对象==，我们可以抽象称为==类==，人属于人类，车属于车类

### 4.1 封装

#### 4.1.1  封装的意义

封装是C++面向对象三大特性之一

封装的意义：

* 将属性和行为作为一个整体，表现生活中的事物
* 将属性和行为加以权限控制
* 可以想一個道理，有人類之後才有我，有我之後才有手腳，也會有行為，像是走路，跑跳等。
* ==類中的屬性和行為，我們統一稱為成員==
  * `類中的屬性`又稱為`成員屬性`或`成員變數`
  * `類中的行為`又稱為`成員函數`



**封装意义一：**

​	在设计类的时候，属性和行为写在一起，表现事物

**语法：** `class 类名{   访问权限： 属性  / 行为  };`



**示例1**：设计一个圆类，求圆的周长

**示例代码：**

```C++
//*********封装的意义*********
//在设计类的时候，属性和行为写在一起，表现事物
//语法： class 类名{ 访问权限： 属性 / 行为 };
// 類中的屬性和行為，我們統一稱為成員
//`類中的屬性`又稱為`成員屬性`或`成員變數`
//`類中的行為`又稱為`成員函數`

#include<iostream>
using namespace std;

//設計一個圓類，求圓的周長
//圓求周長的公式：2*PI*半徑

//圆周率
const double PI = 3.14;

//1、封装的意义
//将属性和行为作为一个整体，用来表现生活中的事物

//封装一个圆类，求圆的周长
//class代表設計一個類，後面跟著是類名稱
class Circle
{
public:  //訪問權限 - 公共的權限

	//屬性
	int m_r;//半徑

	//行為
	//獲取到圓的周長
	double calculateZC()
	{
		//2 * pi  * r
		//获取圆的周长
		return  2 * PI * m_r;
	}
};

int main() {

	// 通过圆类，创建圆的对象
	// 實例化，通過一個類，創建一個對象的過程
	Circle c1;
	c1.m_r = 10; //给圆对象的半径 进行赋值操作

	//2 * pi * 10 = = 62.8
	cout << "圆的周长为： " << c1.calculateZC() << endl;

	system("pause");

	return 0;
}
```





**示例2**：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号





**示例2代码：**

```C++
//*********封装的意义*********
//在设计类的时候，属性和行为写在一起，表现事物
//语法： class 类名{ 访问权限： 属性 / 行为 };
// 類中的屬性和行為，我們統一稱為成員
//`類中的屬性`又稱為`成員屬性`或`成員變數`
//`類中的行為`又稱為`成員函數`

#include<iostream>
using namespace std;

//学生类
class Student {
//屬性
public:
	string m_name;
	int m_id;

//行為
public:
	void setName(string name) {
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}
	void showStudent() {
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
};

int main() {
	//創建一個具體學生
	Student stu;
	//給stu對象，進行一個賦予值的操作
	stu.setName("德玛西亚");
	stu.setID(250);
	//顯示學生信息
	stu.showStudent();


	//創建一個具體學生
	Student stu2;
	//給stu對象，進行一個賦予值的操作
	stu.setName("李四");
	stu.setID(299);
	//顯示學生信息
	stu.showStudent();


	system("pause");

	return 0;
}
```









**封装意义二：**

类在设计时，可以把属性和行为放在不同的权限下，加以控制

访问权限有三种：



1. public  公共权限 - 类内可以访问，类外可以访问
2. protected 保护权限 - 类内可以访问，类外不可以访问，兒子也可以訪問父親中的保護內容
3. private 私有权限 - 内可以访问，类外不可以访问，兒子不可以訪問父親中的私有內容



**示例：**

```C++
//*********封装的意义 - 三種權限*********

#include<iostream>
using namespace std;

//三种权限
//公共权限  public 类内可以访问，类外可以访问
//保护权限  protected 类内可以访问，类外不可以访问，兒子也可以訪問父親中的保護內容
//私有权限  private 類内可以访问，类外不可以访问，兒子不可以訪問父親中的私有內容

class Person
{
	//姓名  公共權限
public:
	string m_Name; //姓名

	//汽车  保护權限
protected:
	string m_Car;

	//银行卡密码  私有權限
private:
	int m_Password;

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
};

int main() {

	Person p;
	p.m_Name = "李四";	//公共權限的內容，類外可以訪問到
	//p.m_Car = "奔驰";  //保護權限的內容，類外訪問不到
	//p.m_Password = 123; //私有權限的內容，類外訪問不到
	cout<<p.m_Name<<endl;

	//可以藉由類內的行為，改變類內的屬性
	p.func();
	cout<<p.m_Name<<endl;

	system("pause");

	return 0;
}
```







#### 4.1.2 struct和class区别



在C++中 struct和class唯一的**区别**就在于 **默认的访问权限不同**

区别：

* struct 默认权限为公共
* class   默认权限为私有


```C++
//*********struct和class的区别*********
//struct 默认权限为公共
//class 默认权限为私有

#include<iostream>
using namespace std;

class C1
{
	int  m_A; //默认是私有权限
};

struct C2
{
	int m_A;  //默认是公共权限
};

int main() {

	C1 c1;
	c1.m_A = 10; //错误，访问权限是私有，所以不能訪問

	C2 c2;
	c2.m_A = 10; //正确，访问权限是公共，所以可以訪問

	system("pause");

	return 0;
}
```













#### 4.1.3 成员属性设置为私有



**优点1**：将所有成员属性设置为私有，可以自己控制读写权限

**优点2**：对于写权限，我们可以检测数据的有效性



**示例**：

```C++
//*********成員屬性設置為私有*********
//1. 可以控制讀寫權限
//2. 對於寫權限，我們可以檢測數據的有效性


#include<iostream>
using namespace std;

class Person {
public:

	//设置姓名 可寫不可讀
	void setName(string name) {
		m_Name = name;
	}

	//獲取姓名 只讀
	string getName()
	{
		return m_Name;
	}

	//获取年龄 只讀
	int getAge() {
		return m_Age;
	}
	//设置年龄 可寫不可讀
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "你个老妖精!" << endl;
			return;
		}
		m_Age = age;
	}

	//情人设置为只写
	void setLover(string lover) {
		m_Lover = lover;
	}

	//獲取情人为只讀
	string getLover() {
		return m_Lover;
	}

private:
	string m_Name; //可读可写  姓名
	int m_Age; //只读  年龄
	string m_Lover; //只写  情人
};


int main() {
	
	Person father;
	//姓名设置
	father.setName("张三");
	cout << "姓名： " << father.getName() << endl;

	//年龄设置
	father.setAge(50);
	cout << "年龄： " << father.getAge() << endl;

	//情人设置
	father.setLover("青空光");
	cout << "情人： " << father.getLover() << endl;
	//cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取

	system("pause");

	return 0;
}
```









**练习案例1：设计立方体类**

设计立方体类(Cube)

求出立方体的面积和体积

分别用全局函数和成员函数判断两个立方体是否相等。



![1545533548532](assets/1545533548532.png)

```c++
//*********練習案例1 - 設計立方體類*********
//求出立方体的面积和体积
//分别用全局函数和成员函数判断两个立方体是否相等。

#include<iostream>
using namespace std;

class Cube {
private:
	float height;
	float width;
	float length;

public:
	//設定長寬高函數，只可以寫
	void setValues(float h, float w, float l){
		height = h;
		width = w;
		length = l;
	}

	//獲取體積數值，只可以讀
	float getVolume(){
		return height*width*length;
	}

	//獲取面積數值，只可以讀
	float getArea(){
		return height*width*2 + width*length*2 + height*length*2;
	}

	//獲取長，只可以讀
	float getLength(){
		return length;
	}

	//獲取寬，只可以讀
	float getWidth(){
		return width;
	}

	//獲取高，只可以讀
	float getHeight(){
		return height;
	}

	//利用函數成員，判斷兩個立方體是否相等
	bool isSameByClass(Cube & cube){	//用引用就不會再拷貝一份數據，比較節省空間
		if (cube.getLength() == length && cube.getWidth() == width && cube.getHeight() == height)
		{
			return true;
		}
		return false;
	}

};

//利用全局函數判斷，判斷兩個立方體是否相等
bool isSame(Cube & cube, Cube & cuboid){	
	//用引用就不會再拷貝一份數據，比較節省空間，
	//雖然函數跑完會釋放記憶體，但用引用就不會再創造新的記憶體空間
	if (cube.getLength() == cuboid.getLength() && cube.getWidth() == cuboid.getWidth() && cube.getHeight() == cuboid.getHeight())
	{
		return true;
	}
	return false;
}

int main() {

	//建立一個正方體
	Cube cube;
	//設定長寬高
	cube.setValues(20,20,20);
	//印出體積以及面積
	cout<<"cube的體積為"<<cube.getVolume()<<endl;
	cout<<"cube的面積為"<<cube.getArea()<<endl;
	

	//建立一個長方體
	Cube cuboid;
	//設定長寬高
	cuboid.setValues(20,20,20);
	//印出體積以及面積
	cout<<"cuboid的體積為"<<cuboid.getVolume()<<endl;
	cout<<"cuboid的面積為"<<cuboid.getArea()<<endl;

	//利用全局函數，判斷兩個立方體是否相等
	cout<<"兩個立方體是否相等"<<isSame(cube, cuboid)<<endl;
	cout<<"兩個立方體是否相等"<<isSame(cube, cuboid)<<endl;

	//利用函數成員，判斷兩個立方體是否相等
	cout<<"兩個立方體是否相等"<<cube.isSameByClass(cuboid)<<endl;
	cout<<"兩個立方體是否相等"<<cube.isSameByClass(cuboid)<<endl;

	system("pause");

	return 0;
};
```









**练习案例2：点和圆的关系**

设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。



![1545533829184](assets/1545533829184.png)


```c++
//*********練習案例2 - 點和圓的關係*********
//點到圓的距離 == 圓的半徑，及為點在圓上
//點到圓的距離 > 圓的半徑，及為點在圓外
//點到圓的距離 < 圓的半徑，及為點在圓內
//點到圓的距離 sqrt((x1-x2)^2 + (y1-y2)^2)

#include<iostream>
using namespace std;

class Point{
private:
	float point_X;
	float point_Y;

public:
	//設置X，只可寫
	void setX(float x){
		point_X = x;
	}

	//獲取X，只可讀
	float getX(){
		return point_X;
	}

	//設置Y，只可寫
	void setY(float y){
		point_Y = y;
	}

	//獲取Y，只可讀
	float getY(){
		return point_Y;
	}
};

class Circle {
private:
	float radius;
	//在類中可以讓另一個類變成成圓
	Point CenterOfCircle;

public:
	//獲取圓的資訊，只可讀
	void getCircleDetail(){
		cout<<"半徑為: "<<radius<<endl;
	}

	//設半徑，只可寫
	void setRadius(float r){
		radius = r;
	}

	//讀取半徑，只可讀
	float getRadius(){
		return radius;
	}
	
	//設圓心，只可寫
	void setCenterOfCircle(Point center){
		
		CenterOfCircle = center;
	}
	
	//獲取圓心
	Point getCenterOfCircle(){
		return CenterOfCircle;
	}
};

//判斷點和圓的關係
void isInCircle(Circle & c, Point & p){
	//計算兩點之間距離的平方
	float distance = 
	(c.getCenterOfCircle().getX()-p.getX()) * (c.getCenterOfCircle().getX()-p.getX()) 
	+ (c.getCenterOfCircle().getY() - p.getY()) * (c.getCenterOfCircle().getY() - p.getY());

	//計算半徑的平方
	float radiusTime2 = c.getRadius() * c.getRadius();

	//判斷關係
	if (distance == radiusTime2){
		cout<<"點在圓上"<<endl;
	}
	else if (distance < radiusTime2){
		cout<<"點在圓外"<<endl;
	}
	else{
		cout<<"點在圓內"<<endl;
	}
}

int main() {

	//設定圓的圓心
	Point CircleCenter;
	CircleCenter.setX(0);
	CircleCenter.setY(0);

	//設定圓c1
	Circle c1;
	c1.setCenterOfCircle(CircleCenter);

	//設定一個點
	Point p;
	p.setX(3.5);
	p.setY(4.6);

	//判斷點在圓心的什麼位置
	isInCircle(c1,p);


	system("pause");

	return 0;
};
```





