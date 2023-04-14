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