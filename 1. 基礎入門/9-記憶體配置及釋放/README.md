# C++基礎入門


## 9 記憶體配置及釋放

### 9.1 malloc 及 new 的差別

1. `malloc` 和 `new` 都是用來動態分配內存的,但是有以下幾點主要區別:

2. `malloc` 是 `C` 語言中的函數,`new` 是 `C++` 中的運算符。

3. `malloc` 分配的是`原始內存`,`new` 分配的是`類型化內存`,包含構造函數的調用。

4. `malloc` 分配的內存需要開發者手動釋放,使用`free函數`;`new`分配的內存有自身的釋放機制,比如`析構函數`。

5. `malloc` 返回的類型是 `void*`, 需要強制類型轉換; `new` 返回對象的`精確類型`。

6. `malloc` 參數只有一個內存大小;`new` 可以有多個其他參數,如構造函數的參數等。

7. malloc是過程化的,簡單靈活;new是面向對象的,與類的概念相結合。

8. **`malloc` 效率略高,直接分配內存;`new` 需要類型檢查和構造,效率略低**。

9. **`malloc` 更底層,通用性更好;`new` 更高級,使用起來更方便簡單。**

**總結來說:**

* malloc底層靈活,但需要手動管理內存;
* new更安全簡單,與面向對象編程結合更好。
* 需要根據具體情況來選擇使用malloc還是new。

### 9.1 malloc
```c++
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

```

### 9.2 new
```c++
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
```



