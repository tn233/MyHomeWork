#include <iostream>
//C++ 列表初始化（初始化变量）
int main(){
    //变量初始化有几种不同形式
    char a = 'A';
    char b = {'A'};
    //char c{'A'};（char不能这样写，但是int可以，具体有待测试）
    //C++ Primer第五版 39-40页，为什么用{}写是不安全丢失数据，其他的则是安全丢失数据？
    char d('A');
    std::cout << a << b << d <<std::endl;
    return 0;
}