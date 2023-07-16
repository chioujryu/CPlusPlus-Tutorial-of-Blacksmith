#include <iostream>
using namespace std;

#include <limits>


// size_t的含义是size type，是一种计数类型。取值范围与机器架构与操作系统相关。32 位机器一般是unsigned int，占 4 字节；而 64 位机器一般是unsigned long，占 8 字节。

// size_t类型常被用作计数用途，例如：sizeof运算符得到对象所占的字节数；字符串函数strlen返回字符串的长度等等，其返回值都为size_t类型。

// size_t类型隐含着本机理论所能容纳建立最大对象的字节数大小的含义，因此常被用于数组索引、内存管理函数中。

// 最初设计size_t类型初衷，是为了程序的跨平台兼容性考虑。

// 在需要通过数组下标来访问数组时，通常建议将下标定义size_t类型，因为一般来说在进行下标访问时，下标都是正的。当然，也不是所有的下标访问操作下标都是正的，比如以下代码：

int main(void) {
    cout<< "size_t 的大小為 " <<sizeof(size_t)<<endl;
    cout << "int数据类型最大值：" << (numeric_limits<size_t>::max)() << endl; 
    cout << "int数据类型最大值：" << (numeric_limits<size_t>::min)() << endl;

    //size_t 的大小這邊如果是 4 byte，代表可能是編譯器調整成 32 bit 了

    int a[10]={1,2,3,4,5,6,7,8,9,10};

    int * ptr = &(a[4]);

    cout<<ptr[-2]<<endl;

}