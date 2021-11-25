#include <iostream>

int main(){
    typedef int happy;//类型别名，定义一个int的别名叫happy，本质上还是int
    happy b = 22222;
    std::cout << b << std::endl;
    using AAA = int;//另一种写法（别名声明）
    
}