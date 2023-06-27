#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>  // 標準算法頭文件

// vector 容器存放內置數據類型
void test01()
{
    // 1. 創建一個 vector 容器 (數組)
    vector<int> v;

    // 2. 向容器中插入數據
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 3. 通過迭代器訪問容器中的數據
    // it_begin 跟 it_end 是指針
    vector<int>::iterator it_begin = v.begin(); // 起始迭代器，指向容器中第一個元素
    vector<int>::iterator it_end = v.end(); // 結束迭代器，指向容器中最後一個元素的下一個位置

    // 4. 第一種遍歷方式
    while (it_begin != it_end)
    {
        cout<<*it_begin<<endl;
        it_begin++;
    }

}

// vector 容器存放內置數據類型
void test02()
{
    // 1. 創建一個 vector 容器 (數組)
    vector<int> v;

    // 2. 向容器中插入數據
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 3. 第二種遍歷方式
    for(vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
    {
        cout<<*it<<endl;
    }
}

void MyPrint(int val);

// vector 容器存放內置數據類型
void test03()
{
    // 1. 創建一個 vector 容器 (數組)
    vector<int> v;

    // 2. 向容器中插入數據
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 3. 第三種遍歷方式，利用STL的遍歷方式，需要導入 <algorithm>
    for_each(v.begin(), v.end(), MyPrint);
}

int main()
{
    //test01();
    //test02();
    test03();

    return 0;
}

void MyPrint(int val)
{
    cout<<val<<endl;
};
