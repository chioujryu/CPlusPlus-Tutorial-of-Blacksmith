#include<iostream>
using namespace std;

//冒泡排序函數（必須熟練的函數）
void bubbleSort(int * arr, int len){
    for(int i=0 ; i<len-1 ; i++){
        for(int j=0 ; j<len-i-1 ; j++){
            //如果j>j+1的值，就交換數字
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }    
    
}

//打印數組
void printArray(int * arr, int len){
    for (int i = 0; i < len; i++){
        cout<<arr[i]<<endl;
    }
}



int main(){

    //1. 先創建數組
    int arr[10] = {4,3,6,9,1,2,10,8,7,5};

    //數組長度
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<len<<endl;

    //2. 創建函數，實現冒泡排序
    bubbleSort(arr,len);

    //3. 打印排序後的數組
    printArray(arr, len);
}