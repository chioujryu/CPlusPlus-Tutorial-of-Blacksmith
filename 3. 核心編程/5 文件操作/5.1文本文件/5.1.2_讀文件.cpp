#include<iostream>
using namespace std;
#include<fstream>	//1. 包含頭文件

void print(char (&buffer)[1024]);

//文本文件 讀文件
void test(){

	//2. 創建輸入流對象
    ifstream ifs;

	//3. 打開文件
	ifs.open("test.txt",ios::in);

	//4. 判斷是否打開成功
	if (!ifs.is_open())
	{
		cout<<"文件打開失敗"<<endl;
		return;
	}
	else if (ifs.is_open())
	{
		cout<<"文件打開成功"<<endl;
	}

	//5.讀數據
	//第一种方式
	char buffer[1024] = { 0 };	// 這個陣列裡面的數值都是 0
	print(buffer);	// 印出陣列
	while (ifs >> buffer)
	{
		cout << buffer << endl;
	}

	//第二种方式
	//char buffer[1024] = { 0 };
	// while (ifs.getline(buffer,sizeof(buffer)))
	// {
	// 	cout << buffer << endl;
	// }

	//第三种方式
	// string buffer;
	// while (getline(ifs, buffer))
	// {
	// 	cout << buffer << endl;
	// }
	
	//第四种方式
	// char c;
	// while ((c = ifs.get()) != EOF)	//EOF = End of File
	// {
	// 	cout << c;
	// }

	//6.關閉文件
	ifs.close();
};

void print(char (&buffer)[1024]){	//用引用接收，才不會讓數組傳指標近來
	int len = sizeof(buffer) / sizeof(buffer[0]);
	cout<<len<<endl;
	for(int i=0; i < len; i++)
	{
		cout<<buffer[i]<<endl;	//ASCII 的 0 為 NULL，所以打印出來會沒有東西
	};
};

int main(){
	
    test();

};