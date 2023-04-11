#include<iostream>
using namespace std;

int main(){

    //指針和數組
    //利用指針訪問數組中的元素

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    cout<<"第一個元素為:"<<arr[0]<<endl;

    int * p = arr; //arr就是數組首地址

    cout<<"利用指針訪問第一個元素:"<<*p<<endl;

    p++; //讓指針向後偏移4個字節


    //利用指針遍歷數組：
    cout<<"利用指針遍歷數組："<<endl;
    int * p2 = arr;
    for (int i = 0; i<10; i++){
        //利用指針遍歷數組
        cout<<*p2<<endl;
        p2++;
    }
}