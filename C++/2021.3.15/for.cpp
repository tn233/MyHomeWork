#include <iostream>

int main(){
    int in = 0,n = 0,n2 = 0;
    std::cout << "请为菱形输入一个值";
    std::cin >> in;
    // <<std::endl
    for(;n<in;n++){
        n2 = 0;
        for(;n2 < ((2*n) - 1);n2++){
            std::cout << "*";
        }
        std::cout << "\n";
    }
}