#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>


void test01(){
    // 1.分配
    uint8_t *ptr = nullptr; 
    ptr = new uint8_t[100]; // 分配100個空間

    // 检查返回的指针是否非空,以确认内存分配是否成功:
    if(ptr != nullptr) {
        printf("分配成功\n");
    } else {
        printf("分配失敗\n");
    }

    // 使用完动态分配的内存后,必须手动释放:
    delete[] ptr;
    ptr = nullptr;
    if(ptr != nullptr) {
        printf("釋放失敗\n");
    } else {
        printf("釋放成功\n");
    }
}

void test02(){

    // 如果只給 intPtr 分配兩個字節，代表只能在 intPtr 指標陣列裡面開闢兩個空間
    uint8_t * intPtr = new uint8_t[2];  // 也可以直接做強轉類型
    intPtr[0] = 244;
    intPtr[1] = 123;
    //intPtr[2] = 111; // 分配過多的空間也可以，但很容易會造成程式崩潰
    for (int i = 0 ; i < 2  ;i++){
        printf("%d\n",intPtr[i] );
    }

    delete[] intPtr;
    intPtr = nullptr;
    if(intPtr != nullptr) {
        printf("釋放失敗\n");
    } else {
        printf("釋放成功\n");
    }
}

int main(){

    test01();
    test02();

}
