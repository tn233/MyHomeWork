#include <iostream>

int main(){
    /**
     * std的命名空间中的io（namespace）
     * istream对象 cin:标准输入
     * ostream对象 cout:输出/cerr:标准错误/clog:调试信息
     * **/

    char a = 'A';
    std::cout << "Hello C++" << std::endl;// <<是输出运算符
    std::string cocoabc = "babbabablaallala";//类型为std::string的变量（std::string是表示可变长字符序列的数据类型）
    //上面的代码可以拆分如下
    std::cout << "Hello C++";
    std::cout << std::endl;//std::endl(被称为操纵符的特殊值)指的是结束,并将与设备关联的缓冲区（buffer）内容刷入设备
    //接上：C++ Primer是这么说的，说白了就是当前的输出流结束获取内容，并输出
    //下面是输入一个char并输出
    std::cin >> a;// >>是输入运算符，类似于scanf("%c",&a);
    std::cout << "Hi," << a << std::endl;//这里的a作用类似于加号，但是实际上是一个链式输出流
    return 0;
}