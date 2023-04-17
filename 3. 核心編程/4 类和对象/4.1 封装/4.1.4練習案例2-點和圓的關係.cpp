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
	else if (distance > radiusTime2){
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