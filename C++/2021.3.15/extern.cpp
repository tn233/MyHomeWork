#include <iostream>
//C++ 分离式编译
extern int apple = 1;//extern声明（变量/函数），可以在多个文件中使用同一个变量
int aaa = 1;//全局作用域(global scope)
int main(){
    int bbb = 1;//块作用域(block scope)
    std::cout << apple << std::endl;
}