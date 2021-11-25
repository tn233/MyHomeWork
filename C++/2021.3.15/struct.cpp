#include <iostream>

struct member{//基本的struct和C差不了太多
    std::string name;//string类型
    int id;
};

int main(){
    struct member a;//和C一样的用法，创建一个名字为a的member数据结构
    a.id = 1;//设置属性
    a.name = "tongnian";
    std::cout << "id:" << a.id << "\nname:" << a.name << std::endl;
}