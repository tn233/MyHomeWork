#include <iostream>
using namespace std;

constexpr int abc(int i){
    return i;
}

//constexpr是C11的标准，暂时没搞清楚是什么作用
const int a = 3.1415 * 3;//常量表达式的值在编译时就得到计算，而且这个东西要写在函数体外边

int main(){
    int b = 0;
    std::cin >> b;
    std::cout << a << abc(b) << std::endl;
    
}