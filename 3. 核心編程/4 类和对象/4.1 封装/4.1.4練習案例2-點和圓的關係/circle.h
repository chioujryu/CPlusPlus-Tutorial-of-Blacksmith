#pragma once //防止頭文件重複
#include<iostream>
#include"point.h"
using namespace std;

class Circle {
private:
	float radius;
	//在類中可以讓另一個類變成成圓
	Point CenterOfCircle;

public:
	//獲取圓的資訊，只可讀
	void getCircleDetail();

	//設半徑，只可寫
	void setRadius(float r);

	//讀取半徑，只可讀
	float getRadius();
	
	//設圓心，只可寫
	void setCenterOfCircle(Point center);
	
	//獲取圓心
	Point getCenterOfCircle();
};