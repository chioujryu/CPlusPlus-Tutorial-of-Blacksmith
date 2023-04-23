#include<iostream>
using namespace std;
#include<fstream>

//文本文件 寫文件
void test(){
    ofstream ofs;
    ofs.open("test.txt",ios::out);

	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	ofs.close();

};

int main(){

    test();

};