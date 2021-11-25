#include <iostream>
//decltype(function()) sum = x;
int funA();//declear

int main(){
    decltype(funA()) sum = 1;//使用funA的类型作为变量sum的类型
    //说白了decltype就是判断其里面的类型
    std::cout << sum << std::endl;
}

int funA(){
    return 0;
}