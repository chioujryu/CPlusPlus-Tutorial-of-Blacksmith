#pragma once //防止頭文件重複
#include<iostream>
using namespace std;

class Point{
private:
	float point_X;
	float point_Y;

public:
	//設置X，只可寫
	void setX(float x);

	//獲取X，只可讀
	float getX();

	//設置Y，只可寫
	void setY(float y);

	//獲取Y，只可讀
	float getY();
};