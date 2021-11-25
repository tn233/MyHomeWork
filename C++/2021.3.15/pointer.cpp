#include <iostream>

int main(){
    //沿袭C?
    //好像并不沿袭C，C用xx = &aa两个的内存地址相同，但这里不是
    int a = 123;
    std::cin >> a;
    int *p2,*pd2,*pc2,*pb2;
    p2 = &a;//p2存放变量a的地址，或者说p2是指向变量a的指针(初始值是int型对象的地址)
    pd2 = p2;//初始值是指向int对象的指针
    pc2 = &a;
    pb2 = pc2;
    std::cout << "p2的指针内容:" << *p2 << "\n";//*的作用是返回对象内容（解引用符），只写指针名或者加&是指针地址
    std::cout << "p2的内存地址:" << &p2 << "\n";
    std::cout << "pd2的内存地址:" << &pd2 << "\n";
    std::cout << "pc2的内存地址:" << &pc2 << "\n";
    std::cout << "pb2的内存地址:" << &pb2 << "\n";
    std::cout << std::endl;
}