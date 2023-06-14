// =======1.2.3 函數模板案例=======
// =======案例描述：
// =======利用函數模板封裝一個排序的函數，可以對 "不同數據類型數組" 進行排序
// =======排序規則從大到小，排序算法爲 "選擇排序"
// =======分別利用 "char數組" 和 "int數組" 進行測試

# include <iostream>
using namespace std;

//交換函數模板
template<typename T>
void mySwap(T &a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}


template<class T> // 也可以替換成typename
//利用選擇排序，進行對數組從大到小的排序（降序排列）
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //最大數的下標
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i) //如果最大數的下標不是i，交換兩者
		{
			mySwap(arr[max], arr[i]);
		}
	}
}

//提供打印數組的模板
template<typename T>
void printArray(T arr[], int len) {

	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void test01()
{
    //測試char數組
    char charArr[] = "asdfdsaf";
    int num = sizeof(charArr)/sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num); 
}

void test02()
{
    //測試int數組
    int intArr[]= {7,5,1,3,9,2,4,6,8};
    int num = sizeof(intArr)/sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}


int main()
{
    test01();
    test02();
    return 0;
}


