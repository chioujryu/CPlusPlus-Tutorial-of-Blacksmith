//*********練習案例2 - 點和圓的關係*********
//點到圓的距離 == 圓的半徑，及為點在圓上
//點到圓的距離 > 圓的半徑，及為點在圓外
//點到圓的距離 < 圓的半徑，及為點在圓內
//點到圓的距離 sqrt((x1-x2)^2 + (y1-y2)^2)

#include<iostream>
#include"circle.h"
#include"point.h"
using namespace std;


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