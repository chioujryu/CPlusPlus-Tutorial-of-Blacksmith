//设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。
//通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
//五名英雄信息如下：
//{"刘备",23,"男"},
//{"关羽",22,"男"},
//{"张飞",20,"男"},
//{"赵云",21,"男"},
//{"貂蝉",19,"女"},

#include<iostream>
using namespace std;

//1. 設計英雄結構體
struct hero
{
	string name;	 //姓名
	int age;	//年齡
	string sex;		//性別
};


//打印所有英雄數據
void printHeros(struct hero Heros[], int len)
{
	for (int i = 0 ; i < len ; i++)
	{
		cout << "姓名： " << Heros[i].name 
				<< " 性别： " << Heros[i].sex 
				<< " 年龄： " << Heros[i].age << endl;
	}
};

//冒泡排序，實現年齡升序排列
void bubbleSort(struct hero Heros[], int len)
{
	for (int i = 0 ; i < len-1 ; i++)
	{
		for (int j = 0 ; j < len-i-1 ; j++)
		{
			//如果j下標的元素年齡大於j+1下標的元素的年齡，交換兩個元素
			if(Heros[j].age>Heros[j+1].age)
			{
				int temp = Heros[j+1].age;
				Heros[j+1].age = Heros[j].age;
				Heros[j].age = temp;
			}
		}
	}
};



int main() {
	//2. 創建數組存放五名英雄
	struct hero heroArray[5] = 
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};

	//3. 取得heroArray的長度
	int len = sizeof(heroArray) / sizeof(heroArray[0]);

	//4. 打印所有英雄信息
	cout<<"打印所有英雄信息"<<endl;
	printHeros(heroArray,len);

	//5. 對數組進行排序，按照年齡進行升序排序
	bubbleSort(heroArray, len);

	//6. 打印排序後的英雄信息
	cout<<"打印排序後的所有英雄信息"<<endl;
	printHeros(heroArray,len);

	return 0;
}