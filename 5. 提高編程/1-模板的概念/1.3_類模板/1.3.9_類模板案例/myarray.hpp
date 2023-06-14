#pragma once
# include <iostream>
using namespace std;
#include <typeinfo> 

// 1. 創建類模板
template<typename T>
class MyArray
{
private:
    T * p_address;  // 指針指向堆區開闢的真實數組
    int m_capacity; // 數組容量
    int m_size; // 數組大小
    
public:
    // 2. 有參構造函數 
    MyArray(int capacity) // 參數 容量
    {
        cout<<"MyArray的有參構造函數調用"<<endl;
        this->m_capacity = capacity;  // 總共的Array容量
        this->m_size = 0;  // Array 裡面現在佔滿幾個空間
        this->p_address = new T[this->m_capacity];  // 開闢新的堆區
    };

    // 3. 拷貝構造函數
    MyArray(const MyArray & arr)
    {
        cout<<"MyArray的拷貝構造函數調用"<<endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;

        // 普通類型可以直接 = 但是指針類型需要深拷貝
        //this->p_address = arr.p_address; // 指針不能附值給指針

        // 深拷貝
        this->p_address = new T[arr.m_capacity];

        // 將arr中的數據都拷貝過來
        for (int i = 0 ; i < this->m_size ; i++)
        {
            //如果T?對象，而且還包含指針，必須需要重載 = 操作符，因?這個等號不是 構造 而是賦值
            this->p_address[i] = arr.p_address[i];
        }
    }

    // 4. operator= 操作符 防止淺拷貝問題 
    MyArray & operator=(const MyArray & arr)
    {
        cout<<"MyArray的 operator= 調用"<<endl;
        // 先判斷原來堆區是否有數據，如果有，先釋放
        if(this->p_address != NULL)
        {
            delete[] this->p_address;
            this->p_address = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // 深拷貝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->p_address = new T[arr.m_capacity];
        for (int i = 0; i < this->m_size ; i++)
        {
            this->p_address[i] = arr.p_address[i];
        }
        return *this; // 因為這個函數是 MyArray 開頭，所以要返回自己
    }

    // 5. 尾插法
    void PuahBack(const T & val) // 使用 const 是因為防止修改val
    {
        // 判斷容量是否等於大小
        if(this->m_capacity == this->m_size)
        {
            return;
        }
        this->p_address[this->m_size] = val; // 在數組的末尾插入數據
        this->m_size++; // 更新數組大小
    }

    // 6. 尾刪法
    void PopBack()
    {
        //讓用戶訪問不到最後一個元素，即為尾刪，邏輯刪除
        if (this->m_size == 0)
        {
            return;
        }
        this->m_size--;
    }

    // 7. 讓用戶通過下標的方式訪問數組中的元素 arr[0] = 100
    T & operator[] (int index)
    {
        return this->p_address[index];
    }

    // 8. 返回數組容量
    int GetCapacity()
    {
        return this->m_capacity;
    }

    // 9. 返回數組大小
    int GetSize()
    {
        return this->m_size;
    }

    // 10. 設計PrintArray函數
    void PrintArray()
    {
        for (int i = 0 ; i < this->m_size ; i++ )
        {
            cout<<this->p_address[i]<<endl;
        }
    }

    // 11. 析構函數
    ~MyArray()
    {
        cout<<"MyArray的析構函數調用"<<endl;
        if (this->p_address != NULL)
        {
            delete[] this->p_address;
            this->p_address = NULL;
        }
    }
};