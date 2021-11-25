#include <iostream>

using std::string;//using-NameSpace的用法



int main(){
    string s1;//生成一个空字符串s1
    string s2 = s1;//生成一个s2，内容和s1相同（空）
    string s3 = "happy";//这不用多说吧，他还有一个另类写法：string s3("happy");
    string s4(10,'7');//生成10个7

    return 0;
}