# 通訊錄管理系統



## 1、系統需求

通訊錄是一個可以記錄親人、好友信息的工具。

本教程主要利用C++來實現一個通訊錄管理系統

系統中需要實現的功能如下：

* 添加聯繫人：向通訊錄中添加新人，信息包括（姓名、性別、年齡、聯繫電話、家庭住址）最多記錄1000人
* 顯示聯繫人：顯示通訊錄中所有聯繫人信息
* 刪除聯繫人：按照姓名進行刪除指定聯繫人
* 查找聯繫人：按照姓名查看指定聯繫人信息
* 修改聯繫人：按照姓名重新修改指定聯繫人
* 清空聯繫人：清空通訊錄中所有信息
* 退出通訊錄：退出當前使用的通訊錄









## 2、創建項目

創建項目步驟如下：

* 創建新項目
* 添加文件

### 2.1 創建項目

打開vs2017後，點擊創建新項目，創建新的C++項目

![1544151401138](assets/1544151401138.png)



填寫項目名稱，選擇項目路徑

![1544151579620](assets/1544151579620.png)

### 2.2添加文件

![1544161551746](assets/1544161551746.png)



![1544161648175](assets/1544161648175.png)

添加成功後，效果如圖：

![1544162344057](assets/1544162344057.png)



至此，項目已創建完畢







## 3、菜單功能

**功能描述：** 用戶選擇功能的界面

菜單界面效果如下圖：



![1544149559893](assets/1544149559893.png)

**步驟：**

* 封裝函數顯示該界面  如 `void showMenu()`
* 在main函數中調用封裝好的函數



**代碼：**

```C++
#include<iostream>
using namespace std;

//build Menu
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1 add contacts  *****" << endl;
	cout << "*****  2 show contacts  *****" << endl;
	cout << "*****  3 delete contacts  *****" << endl;
	cout << "*****  4 find contacts  *****" << endl;
	cout << "*****  5 modify contacts  *****" << endl;
	cout << "*****  6 clean all contacts  *****" << endl;
	cout << "*****  0 shut down machine  *****" << endl;
	cout << "***************************" << endl;
}

int main() {

	showMenu();

	system("pause");

	return 0;
}
```









## 4、退出功能

功能描述：退出通訊錄系統



思路：根據用戶不同的選擇，進入不同的功能，可以選擇switch分支結構，將整個架構進行搭建



當用戶選擇0時候，執行退出，選擇其他先不做操作，也不會退出程序



**代碼：**

```C++
int main() {

	int select = 0;

	while (true)
	{
		showMenu();

		cin >> select;
		
		switch (select)
		{
		case 1:  //add contacts
            addPerson(&abs); //Using address passing, you can modify actual parameters.
			break;
		case 2:  //show contacts
            showContacts(&abs);
			break;
		case 3:  //delete contacts 
            deleteContact(&abs);
			break;
		case 4:  //find contacts
            findContact(&abs);
			break;
		case 5:  //modify contacts
            modifyContact(&abs);
			break;
		case 6:  //empty contacts
            cleanPerson(&abs);
			break;
		case 0:  //shut down machine
			cout << "I am happy to serve you" << endl;
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
```



效果圖：

![1544163868043](assets/1544163868043.png)











## 5、添加聯繫人

功能描述：

實現添加聯繫人功能，聯繫人上限為1000人，聯繫人信息包括（姓名、性別、年齡、聯繫電話、家庭住址）



添加聯繫人實現步驟：

* 設計聯繫人結構體
* 設計通訊錄結構體
* main函數中創建通訊錄
* 封裝添加聯繫人函數
* 測試添加聯繫人功能



### 5.1 設計聯繫人結構體

聯繫人信息包括：姓名、性別、年齡、聯繫電話、家庭住址

設計如下：

```C++
#include <string>  //string頭文件
//bulid Person structure
struct Person
{
	string m_Name; //name
	int m_Sex; //sex
	int m_Age; //age
	string m_Phone; //phone
	string m_Addr; //address
};
```



### 5.2 設計通訊錄結構體

設計時候可以在通訊錄結構體中，維護一個容量為1000的存放聯繫人的數組，並記錄當前通訊錄中聯繫人數量

設計如下

```C++
//build Addressbooks structure
#define MAX 1000 //Max number of people
struct Addressbooks
{
    struct Person personArray[MAX]; //The maximum number of contacts that your address book can accommodate
    int m_Size; //the current number of contacts in your address book
};
```



### 5.3 main函數中創建通訊錄



添加聯繫人函數封裝好後，在main函數中創建一個通訊錄變量，這個就是我們需要一直維護的通訊錄



```c++
mian函數起始位置添加：

int main() {

    //build Addressbooks
    struct Addressbooks abs;
    abs.m_Size = 0;

```





### 5.4 封裝添加聯繫人函數



思路：添加聯繫人前先判斷通訊錄是否已滿，如果滿了就不再添加，未滿情況將新聯繫人信息逐個加入到通訊錄



添加聯繫人代碼：



```C++
//1. add contacts
void addPerson(struct Addressbooks * abs)
{
    //Check if address book is full, no more adding. 
    if(abs->m_Size > MAX)
    {
        cout << "Sorry, cannot add. Address book already full." << endl;
		return;
    }
    else
    {
        //name
        string name;
        cout<<"please enter your name"<<endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //sex
        cout<<"please enter your sex"<<endl;
        cout<<"1 -- male"<<endl;
        cout<<"0 -- female"<<endl;
        int sex = 0;
        while(1)
        {
            cin>>sex;
            if (sex == 1 || sex == 0)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout<<"Input error, please enter your sex"<<endl;
                cout<<"1 -- male"<<endl;
                cout<<"2 -- female"<<endl;
            }
        }
        
        //age
        cout<<"please enter your age"<<endl;
        int Age;
        cin>>Age;
        abs->personArray[abs->m_Size].m_Age = Age;

        //Phone
        cout<<"please enter your phone"<<endl;
        string Phone;
        cin>>Phone;
        abs->personArray[abs->m_Size].m_Phone = Phone;

        //Address
        cout<<"please enter your address"<<endl;
        string Address;
        cin>>Address;
        abs->personArray[abs->m_Size].m_Addr = Address;

        //update m_Size
        abs->m_Size++;

        cout<<"Great news! You have successfully added a new contact."<<endl;
        system("pause"); //pause terminal
        system("cls"); //clear terminal
    }   
}
```







### 5.5 測試添加聯繫人功能

選擇界面中，如果玩家選擇了1，代表添加聯繫人，我們可以測試下該功能



在switch case 語句中，case1裡添加：

```C++
case 1:  //add contacts
	addContacts(&abs); //Using address passing, you can modify actual parameters.
	break;
```



測試效果如圖：

![1544165554002](assets/1544165554002.png)









## 6、顯示聯繫人

功能描述：顯示通訊錄中已有的聯繫人信息



顯示聯繫人實現步驟：

* 封裝顯示聯繫人函數
* 測試顯示聯繫人功能

### 6.1 封裝顯示聯繫人函數



思路：判斷如果當前通訊錄中沒有人員，就提示記錄為空，人數大於0，顯示通訊錄中信息



顯示聯繫人代碼：

```C++
//2. show contacts
void showContacts(struct Addressbooks * abs)
{
    if (abs->m_Size == 0)
    {
        cout<<"Your address boos is empty"<<endl;
    }
    else
    {
        for (int i = 0 ; i < abs->m_Size ; i++)
        {
			cout << "Name:" << abs->personArray[i].m_Name << "\t";
			cout << "Sex:" << (abs->personArray[i].m_Sex == 1 ? "male" : "female") << "\t";
			cout << "Age:" << abs->personArray[i].m_Age << "\t";
			cout << "Phone" << abs->personArray[i].m_Phone << "\t";
			cout << "Address:" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}
```





### 6.2 測試顯示聯繫人功能



在switch case語句中，case 2 裡添加

```C++
case 2:  //show contacts
	showContacts(&abs);
	break;
```



測試效果如圖：

![1544166401582](assets/1544166401582.png)









## 7、刪除聯繫人

功能描述：按照姓名進行刪除指定聯繫人



刪除聯繫人實現步驟：

* 封裝檢測聯繫人是否存在
* 封裝刪除聯繫人函數
* 測試刪除聯繫人功能





### 7.1  封裝檢測聯繫人是否存在

設計思路：



刪除聯繫人前，我們需要先判斷用戶輸入的聯繫人是否存在，如果存在刪除，不存在提示用戶沒有要刪除的聯繫人

因此我們可以把檢測聯繫人是否存在封裝成一個函數中，如果存在，返回聯繫人在通訊錄中的位置，不存在返回-1



檢測聯繫人是否存在代碼：

```C++
//Checking if contact exists. Return position if exists, else return -1.
int isExist(struct Addressbooks * abs, string name)
{
    for (int i = 0 ; i < abs->m_Size ; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;  //found contact, return his index
        }
    }
    return -1;  //if not found iterating, return `-1`
}

```



### 7.2 封裝刪除聯繫人函數



根據用戶輸入的聯繫人判斷該通訊錄中是否有此人

查找到進行刪除，並提示刪除成功

查不到提示查無此人。



```C++
//3. delete contact
void deleteContact(struct Addressbooks * abs)
{
    string name;
    cout<<"enter a name contact you want to delete"<<endl;
    cin>>name;
    int number = isExist(abs, name);
    if (number == -1)
    {
        cout<<"Can't delete, contact not in address book."<<endl;
    }
    else
    {
        //Contact found, delete contact
        for (int i = number ; i < abs->m_Size ; i++)
        {
            //moving data forward
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;  //update personnel count in address book
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}
```



### 7.3 測試刪除聯繫人功能

在switch case 語句中，case3裡添加：

```C++
case 3:  //delete contacts 
	deleteContact(&abs);
	break;
```

測試效果如圖：

存在情況：

![1544167951559](assets/1544167951559.png)

不存在情況：

![1544168010831](assets/1544168010831.png)









## 8、查找聯繫人

功能描述：按照姓名查看指定聯繫人信息

查找聯繫人實現步驟

* 封裝查找聯繫人函數
* 測試查找指定聯繫人

### 8.1 封裝查找聯繫人函數

實現思路：判斷用戶指定的聯繫人是否存在，如果存在顯示信息，不存在則提示查無此人。

查找聯繫人代碼：

```C++
//4. find contact
void findContact(struct Addressbooks * abs)
{
    cout<<"enter a contact you want to check"<<endl;
    string name;
    cin >> name;

    //Checking if the specified contact is in the address book.
    int index = isExist(abs,name);
    if (index == -1)
    {
        cout<<"can not find the specified contact"<<endl;
    }
    else
    {
        showContactDetail(abs,index);
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}
```



### 8.2 測試查找指定聯繫人

在switch case 語句中，case4裡添加：

```C++
case 4:  //find contacts
	findContact(&abs);
	break;
```



測試效果如圖

存在情況：

![1544170057646](assets/1544170057646.png)



不存在情況：

![1544170254021](assets/1544170254021.png)









## 9、修改聯繫人

功能描述：按照姓名重新修改指定聯繫人

修改聯繫人實現步驟

* 封裝修改聯繫人函數
* 測試修改聯繫人功能



### 9.1 封裝修改聯繫人函數

實現思路：查找用戶輸入的聯繫人，如果查找成功進行修改操作，查找失敗提示查無此人



修改聯繫人代碼：

```C++
//5. modify contact
void modifyContact(struct Addressbooks * abs)
{
    cout<<"enter a contact you want to modify"<<endl;
    string name;
    cin >> name;

    //Checking if the specified contact is in the address book.
    int index = isExist(abs,name);
    if (index == -1)
    {
        cout<<"can not find the specified contact"<<endl;
    }
    else
    {
        //modify name
        cout<<"modify the name"<<endl;
        string name;
        cin>>name;
        abs->personArray[index].m_Name = name;

        //modify sex
        cout<<"modify the sex"<<endl;
        cout<<"1 -- male"<<endl;
        cout<<"0 -- female"<<endl;
        int sex;
        cin>>sex;
        while(true)
        {
            if (sex == 0 || sex == 1)
            {
                //valid input, exit the loop
                abs->personArray[index].m_Sex = sex;
                break;
            }
            else
            {
                //invalid input
                cout<<"Invalid input"<<endl;
                break;
            }
        }

        //modify age
        cout<<"modify the age"<<endl;
        int age;
        cin>>age;
        abs->personArray[index].m_Age = age;

        //modify phone
        cout<<"modify the phone"<<endl;
        int phone;
        cin>>phone;
        abs->personArray[index].m_Phone = phone;

        //modify address
        cout<<"modify the address"<<endl;
        string address;
        cin>>address;
        abs->personArray[index].m_Addr = address;
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}
```





### 9.2 測試修改聯繫人功能

在switch case 語句中，case 5裡添加：

```C++
case 5:  //modify Contact
	modifyContact(&abs);
	break;
```



測試效果如圖：

查不到指定聯繫人情況：

![1544172265676](assets/1544172265676.png)

查找到聯繫人，並修改成功：

![1544172164141](assets/1544172164141.png)

再次查看通訊錄，確認修改完畢

![1544172228627](assets/1544172228627.png)









## 10、清空聯繫人

功能描述：清空通訊錄中所有信息

清空聯繫人實現步驟

* 封裝清空聯繫人函數
* 測試清空聯繫人

### 10.1 封裝清空聯繫人函數

實現思路： 將通訊錄所有聯繫人信息清除掉，只要將通訊錄記錄的聯繫人數量置為0，做邏輯清空即可。

清空聯繫人代碼：

```C++
//6. clean all contacts
void cleanAllcontacts(struct Addressbooks * abs)
{
    abs->m_Size = 0;    //Set the number of current recorded contacts to 0 to logically clear them.
    cout<<"The address book has been cleared"<<endl;
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}
```



### 10.2  測試清空聯繫人

在switch case 語句中，case 6 裡添加：

```C++
case 6:  //empty contacts
	cleanAllcontacts(&abs);
	break;
```



測試效果如圖：

清空通訊錄

![1544172909693](assets/1544172909693.png)

再次查看信息，顯示記錄為空

![1544172943653](assets/1544172943653.png)



**至此，通訊錄管理系統完成！**

**我們來查看最後的程式碼**
```c++
#include<iostream>
using namespace std;

//build Menu
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1 add contacts  *****" << endl;
	cout << "*****  2 show contacts  *****" << endl;
	cout << "*****  3 delete contacts  *****" << endl;
	cout << "*****  4 find contacts  *****" << endl;
	cout << "*****  5 modify contacts  *****" << endl;
	cout << "*****  6 clean all contacts  *****" << endl;
	cout << "*****  0 shut down machine  *****" << endl;
	cout << "***************************" << endl;
}

//bulid Person structure
struct Person
{
	string m_Name; //name
	int m_Sex; //sex
	int m_Age; //age
	string m_Phone; //phone
	string m_Addr; //address
};

//build Addressbooks structure
#define MAX 1000 //Max number of people
struct Addressbooks
{
    struct Person personArray[MAX]; //The maximum number of contacts that your address book can accommodate
    int m_Size; //the current number of contacts in your address book
};

//1. add contacts
void addContacts(struct Addressbooks * abs)
{
    //Check if address book is full, no more adding. 
    if(abs->m_Size > MAX)
    {
        cout << "Sorry, cannot add. Address book already full." << endl;
		return;
    }
    else
    {
        //name
        string name;
        cout<<"please enter your name"<<endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //sex
        cout<<"please enter your sex"<<endl;
        cout<<"1 -- male"<<endl;
        cout<<"0 -- female"<<endl;
        int sex = 0;
        while(1)
        {
            cin>>sex;
            if (sex == 1 || sex == 0)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout<<"Input error, please enter your sex"<<endl;
                cout<<"1 -- male"<<endl;
                cout<<"2 -- female"<<endl;
            }
        }
        
        //age
        cout<<"please enter your age"<<endl;
        int Age;
        cin>>Age;
        abs->personArray[abs->m_Size].m_Age = Age;

        //Phone
        cout<<"please enter your phone"<<endl;
        string Phone;
        cin>>Phone;
        abs->personArray[abs->m_Size].m_Phone = Phone;

        //Address
        cout<<"please enter your address"<<endl;
        string Address;
        cin>>Address;
        abs->personArray[abs->m_Size].m_Addr = Address;

        //update m_Size
        abs->m_Size++;

        cout<<"Great news! You have successfully added a new contact."<<endl;
        system("pause"); //pause terminal
        system("cls"); //clear terminal
    }   
}

//2. show contacts
void showContacts(struct Addressbooks * abs)
{
    if (abs->m_Size == 0)
    {
        cout<<"Your address boos is empty"<<endl;
    }
    else
    {
        for (int i = 0 ; i < abs->m_Size ; i++)
        {
			cout << "Name:" << abs->personArray[i].m_Name << "\t";
			cout << "Sex:" << (abs->personArray[i].m_Sex == 1 ? "male" : "female") << "\t";
			cout << "Age:" << abs->personArray[i].m_Age << "\t";
			cout << "Phone" << abs->personArray[i].m_Phone << "\t";
			cout << "Address:" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}

//Checking if contact exists. Return position if exists, else return -1.
int isExist(struct Addressbooks * abs, string name)
{
    for (int i = 0 ; i < abs->m_Size ; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;  //found contact, return his index
        }
    }
    return -1;  //if not found iterating, return `-1`
}

//3. delete contact
void deleteContact(struct Addressbooks * abs)
{
    string name;
    cout<<"enter a name contact you want to delete"<<endl;
    cin>>name;
    int number = isExist(abs, name);
    if (number == -1)
    {
        cout<<"Can't delete, contact not in address book."<<endl;
    }
    else
    {
        //Contact found, delete contact
        for (int i = number ; i < abs->m_Size ; i++)
        {
            //moving data forward
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;  //update personnel count in address book
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}

void showContactDetail(struct Addressbooks * abs, int index)
{
    cout << "Name:" << abs->personArray[index].m_Name << "\t";
    cout << "Sex:" << (abs->personArray[index].m_Sex == 1 ? "male" : "female") << "\t";
    cout << "Age:" << abs->personArray[index].m_Age << "\t";
    cout << "Phone" << abs->personArray[index].m_Phone << "\t";
    cout << "Address:" << abs->personArray[index].m_Addr << endl;
}

//4. find contact
void findContact(struct Addressbooks * abs)
{
    cout<<"enter a contact you want to check"<<endl;
    string name;
    cin >> name;

    //Checking if the specified contact is in the address book.
    int index = isExist(abs,name);
    if (index == -1)
    {
        cout<<"can not find the specified contact"<<endl;
    }
    else
    {
        showContactDetail(abs,index);
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}

//5. modify contact
void modifyContact(struct Addressbooks * abs)
{
    cout<<"enter a contact you want to modify"<<endl;
    string name;
    cin >> name;

    //Checking if the specified contact is in the address book.
    int index = isExist(abs,name);
    if (index == -1)
    {
        cout<<"can not find the specified contact"<<endl;
    }
    else
    {
        //modify name
        cout<<"modify the name"<<endl;
        string name;
        cin>>name;
        abs->personArray[index].m_Name = name;

        //modify sex
        cout<<"modify the sex"<<endl;
        cout<<"1 -- male"<<endl;
        cout<<"0 -- female"<<endl;
        int sex;
        cin>>sex;
        while(true)
        {
            if (sex == 0 || sex == 1)
            {
                //valid input, exit the loop
                abs->personArray[index].m_Sex = sex;
                break;
            }
            else
            {
                //invalid input
                cout<<"Invalid input"<<endl;
                break;
            }
        }

        //modify age
        cout<<"modify the age"<<endl;
        int age;
        cin>>age;
        abs->personArray[index].m_Age = age;

        //modify phone
        cout<<"modify the phone"<<endl;
        int phone;
        cin>>phone;
        abs->personArray[index].m_Phone = phone;

        //modify address
        cout<<"modify the address"<<endl;
        string address;
        cin>>address;
        abs->personArray[index].m_Addr = address;
    }
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}

//6. clean all contacts
void cleanAllcontacts(struct Addressbooks * abs)
{
    abs->m_Size = 0;    //Set the number of current recorded contacts to 0 to logically clear them.
    cout<<"The address book has been cleared"<<endl;
    system("pause"); //pause terminal
    system("cls"); //clear terminal
}



int main() {

    //build Addressbooks
    struct Addressbooks abs;
    abs.m_Size = 0;


	int select = 0;

	while (true)
	{
		showMenu();

		cin >> select;
		
		switch (select)
		{
		case 1:  //add contacts
            addContacts(&abs); //Using address passing, you can modify actual parameters.
			break;
		case 2:  //show contacts
            showContacts(&abs);
			break;
		case 3:  //delete contacts 
            deleteContact(&abs);
			break;
		case 4:  //find contacts
            findContact(&abs);
			break;
		case 5:  //modify contacts
            modifyContact(&abs);
			break;
		case 6:  //empty contacts
            cleanAllcontacts(&abs);
			break;
		case 0:  //shut down machine
			cout << "I am happy to serve you" << endl;
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}

```