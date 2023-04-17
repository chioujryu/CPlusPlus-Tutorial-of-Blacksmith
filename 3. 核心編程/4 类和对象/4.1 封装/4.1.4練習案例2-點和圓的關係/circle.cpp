#include"circle.h"

//獲取圓的資訊，只可讀
void Circle::getCircleDetail(){
	cout<<"半徑為: "<<radius<<endl;
}

//設半徑，只可寫
void Circle::setRadius(float r){
	radius = r;
}

//讀取半徑，只可讀
float Circle::getRadius(){
	return radius;
}

//設圓心，只可寫
void Circle::setCenterOfCircle(Point center){
	
	CenterOfCircle = center;
}

//獲取圓心
Point Circle::getCenterOfCircle(){
	return CenterOfCircle;
}
