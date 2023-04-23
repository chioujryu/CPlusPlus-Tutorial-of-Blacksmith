#include <iostream>
using namespace std;

//必須用引用的方式傳入，這樣傳入的數組才不會是指標
void printttint(int (&arr)[5]) {
  int len = sizeof(arr) / sizeof(arr[0]);
  cout << sizeof(arr) << endl;
};

int main() {
  int arr[] = {1, 2, 3, 4, 22};
  printttint(arr);
  return 0;
};