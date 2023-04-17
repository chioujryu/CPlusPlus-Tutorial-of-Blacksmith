#include"point.h"


//設置X，只可寫
void Point::setX(float x){
	point_X = x;
}

//獲取X，只可讀
float Point::getX(){
	return point_X;
}

//設置Y，只可寫
void Point::setY(float y){
	point_Y = y;
}

//獲取Y，只可讀
float Point::getY(){
	return point_Y;
}
