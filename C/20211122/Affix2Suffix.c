#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int data[100];
    int pointer;
}list;

int push(list *list,int number);
int pop(list *list);
list init();

int Affix2Suffix(char *input,int len,char *res);
int Affix2Prefix(char *input,int len,char *res);
int Prefix_Calculate(char *input,int len);
int Suffix_Calculate(char *input,int len);

int main(){
    printf("请输入中缀表达式:");
    //"(3+4)*5-6"
    //1+((2+3)*4)-5
    
    char *input = (char*)calloc(0,500);
    scanf("%s",input);
    char *Suffix = (char*)calloc(1,500);
    char *Prefix = (char*)calloc(1,500);
    Affix2Prefix(input,strlen(input),Prefix);
    Affix2Suffix(input,strlen(input),Suffix);
    printf("前缀表达式为:%s\n",Prefix);
    int res = Prefix_Calculate(Prefix,strlen(Prefix));
    printf("计算结果为:%d\n",res);

    printf("后缀表达式为:%s\n",Suffix);
    int res2 = Suffix_Calculate(Suffix,strlen(Suffix));
    printf("\n计算结果为:%d\n",res2);

    //Affix2Suffix(input,strlen(input));
    //int Suffix_Calc = Prefix_Calculate(&Suffix,strlen(Suffix));
    
    //printf("前缀表达式计算结果为:%d",Suffix_Calc);
    printf("\n");
    
}

int Affix2Prefix(char *input,int len,char *res){
    //printf("len:%d\n",len);
    list s1 = init();//运算符栈
    list s2 = init();//储存中间结果

    //其实中缀转前缀和后缀的操作思想相同
    //只是转前缀是从右向左的顺序

    int i = len - 1;

    for(;i > -1;i--){
        int operate = input[i];
        //printf("%c\n",input[i]);
        if(operate > 47 && operate < 58){//遇到操作数
            push(&s2,operate);
        }else{//遇到运算符
            while(1){
                int stack_top = s1.data[s1.pointer];
                int add = stack_top + operate;
                //奇技淫巧，在前面做stack_top校验纯粹避免bug(两个不相干的数字可以组合成这一套数字)
                int equal = (stack_top == 42 || stack_top == 47) && (add == 84 || add == 94 || add == 89);//扫描优先级等于栈顶优先级(乘除)
                int equal2 = (stack_top == 43 || stack_top == 45) && (add == 86 || add == 90 || add == 88);//同上(加减)
                int logic = (operate == 42 || operate == 47) && (stack_top == 43 || stack_top == 45);//扫描优先级高于栈顶优先级
                //如果s1为空/栈顶运算符为“)”/扫描到“)” -> 直接入栈
                if(s1.pointer == -1 || stack_top == 41 || operate == 41){
                    push(&s1,operate);
                    break;
                }else if(operate == 40){//遇到 “(”
                    while(1){
                        int p = pop(&s1);
                        if(p != -1 && p != 41){
                            push(&s2,p);
                        }else{//栈为空或者遇到了“)”则跳出
                            break;
                        }
                    }
                    break;
                }else if(logic || equal || equal2){
                    //当前扫描的优先级高于或等于栈顶的优先级
                    push(&s1,operate);
                    break;
                }else{//如果优先级小于或等于，弹出s1栈顶并压入s2再次与新的栈顶做比较
                    int p = pop(&s1);
                    push(&s2,p);
                    continue;
                }
            }
        }
    }

    while(1){
        int p = pop(&s1);
        if(p == -1){
            break;
        }
        push(&s2,p);
    }

    int a = 0,out = 0;
    while(1){
        out = pop(&s2);
        if(out == -1){
            break;
        }
        res[a] = out;
        a++;
    }
    res[a] = '\0';
    return 0;
}

int Affix2Suffix(char *input,int len,char *res){
    printf("len:%d\n",len);
    list s1 = init();//运算符栈
    list s2 = init();//储存中间结果

    //其实中缀转前缀和后缀的操作思想相同
    //只是转前缀是从右向左的顺序

    int i = 0;//strlen有个"\0"要去掉
    
    //int num_tmp = 0;//用于个位数以上
    for(;i < len;i++){//必须减一，不然字符串后的\0直接导致程序输出错误
        int operate = input[i];
        //printf("%c\n",input[i]);
        if(operate > 47 && operate < 58){//遇到操作数
            push(&s2,operate);
        }else{//遇到运算符
            while(1){
                int stack_top = s1.data[s1.pointer];

                //如果s1为空/栈顶运算符为“(”/扫描到“(” -> 直接入栈
                if(s1.pointer == -1 || stack_top == 40 || operate == 40){
                    push(&s1,operate);
                    break;
                }else if(operate == 41){//遇到 “)”
                    while(1){
                        int p = pop(&s1);
                        if(p != -1 && p != 40){
                            push(&s2,p);
                        }else{//栈为空或者遇到了“(”则跳出
                            break;
                        }
                    }
                    break;
                }else if((operate == 42 || operate == 47) && (stack_top == 43 || stack_top == 45)){
                    //当前扫描的优先级高于栈顶的优先级
                    push(&s1,operate);
                    break;
                }else{//如果优先级小于或等于，弹出s1栈顶并压入s2再次与新的栈顶做比较
                    int p = pop(&s1);
                    push(&s2,p);
                    continue;
                }
            }
        }
    }

    while(1){
        int p = pop(&s1);
        if(p == -1){
            break;
        }
        push(&s2,p);
    }

    list result = init();//结果栈
    while(1){
        int out = pop(&s2);
        if(out == -1){
            break;
        }
        push(&result,out);
        
    }
    //利用栈进行倒序
    int a = 0;
    while(1){
        int out = pop(&result);
        if(out == - 1){
            break;
        }
        res[a] = out;
        a++;
    }
    res[a] = '\0';
    return 0;
}

int Prefix_Calculate(char *input,int len){
    int i = len - 1;
    list calc = init();
    
    //int num_tmp = 0;//用于个位数以上
    for(;i > -1;i--){
        int operate = input[i];
        if(operate > 47 && operate < 58){//遇到操作数
            int number = operate - 48;//ascii to int
            push(&calc,number);
            continue;
        }

        int a = pop(&calc);
        int b = pop(&calc);
        switch(operate){
            case 43:// +
                push(&calc,a+b);
            break;
            case 45:// -
                push(&calc,a-b);
            break;
            case 42:// *
                push(&calc,a*b);
            break;
            case 47:// "/"
                push(&calc,a/b);
            break;
        }
    }
    return pop(&calc);
}

int Suffix_Calculate(char *input,int len){
    int i = 0;
    list calc = init();
    
    //int num_tmp = 0;//用于个位数以上
    for(;i < len;i++){
        int operate = input[i];
        if(operate > 47 && operate < 58){//遇到操作数
            int number = operate - 48;//ascii to int
            push(&calc,number);
            continue;
        }

        int a = pop(&calc);
        int b = pop(&calc);
        switch(operate){
            //后缀表达计算是次栈顶（+-*/）栈顶
            //前缀计算使用栈顶（+-*/）次栈顶
            case 43:// +
                push(&calc,b+a);
            break;
            case 45:// -
                push(&calc,b-a);
            break;
            case 42:// *
                push(&calc,b*a);
            break;
            case 47:// "/"
                push(&calc,b/a);
            break;
        }
    }
    return pop(&calc);
}

int push(list *list,int number){//入栈
    list->pointer++;
    list->data[list->pointer] = number;
    return 0;
}

int pop(list *list){//出栈
    if(list->pointer == -1){
        return -1;
    }

    int result = list->data[list->pointer];
    list->data[list->pointer] = -1;
    list->pointer--;

    return result;
}

list init(){
    list q;
    q.pointer = -1;
    return q;
}