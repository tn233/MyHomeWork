#include <iostream>

int main(){//&指的是引用符
    int a = 1;
    int &b = a;//b指向a(b引用a)，相当于一个分身，a值变了b值也会变，反之亦然
    return 0; 
}