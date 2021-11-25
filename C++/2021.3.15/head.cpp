#include "./head.h" //引用head.h(使用路径，使用<>的一般都是C自带库，如果需要使用外部库使用include “path”)
//如果h文件和cpp文件在同一文件夹，使用"./"即可（还要摸索，没摸透）

int main(){
    struct bingo b;
    b.name = "tongnianshanhe";
    std::cout << "My name is " << b.name << std::endl;
    return 0;
}