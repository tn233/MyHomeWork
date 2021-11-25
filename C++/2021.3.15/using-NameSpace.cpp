#include <iostream>

using std::cin;
//using std::cout; //略略略
//using std::endl; //略略略
int main(){
    int i = 123;
    int b = 0;
    cin >> b;
    std::cout << i + b << std::endl;
    //cout << i + b << endl; //如果要这样用，那么需要这段代码里的第四行第五行
    //注意:头文件不应该包含using声明，因为这样每个使用了这个头文件的代码都会包含这个声明，有可能会导致重复包含甚至命名冲突等问题
}