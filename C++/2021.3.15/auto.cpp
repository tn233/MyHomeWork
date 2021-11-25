#include <iostream>

using namespace std;
//auto 让编译器自己去判断赋值的类型并“变成”此种类型
int main(){
    auto i = 0 , b = 14;//如果这样连用，那么这一行所有的变量类型必须相同
    std::cout << i <<std::endl;//auto不能用于函数体外（全局空间）
}