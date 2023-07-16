// 用法:
// 包含头文件:#include <stdlib.h>
// 调用malloc并传递需要的内存块大小size:

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void test01(){

    void *ptr = nullptr; 
    ptr = malloc(100); // 分配100个字节

    // 检查返回的指针是否非空,以确认内存分配是否成功:
    if(ptr != NULL) {
        printf("分配成功\n");
    } else {
        printf("分配失敗\n");
    }

    // 使用完动态分配的内存后,必须手动释放:
    free(ptr);
    ptr = NULL;
    if(ptr != NULL) {
        printf("釋放失敗\n");
    } else {
        printf("釋放成功\n");
    }

}

void test02(){
    // 如果只給 intPtr 分配兩個字節，代表只能在 intPtr 指標陣列裡面開闢兩個空間
    uint8_t * intPtr = (uint8_t *)malloc(2);  // 也可以直接做強轉類型
    intPtr[0] = 244;
    intPtr[1] = 123;
    //intPtr[2] = 111; // 分配過多的空間也可以，但很容易會造成程式崩潰
    for (int i = 0 ; i < 2  ;i++){
        printf("%d\n",intPtr[i] );
    }

    free(intPtr);
    intPtr = NULL;
    if(intPtr != NULL) {
        printf("釋放失敗\n");
    } else {
        printf("釋放成功\n");
    }
}

int main(){

    test01();
    test02();

}
