#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct str{
    char word;
    struct str *next;
}string;

int compare(string *str,string *main_str);
string *new_string(char str[]);

//BF算法
int main(){
    int a = compare(new_string("abc"),new_string("abcdabce"));
    printf("匹配个数:%d",a);
}

string *new_string(char str[]){
    string *head = (string*)malloc(sizeof(string));
    int i = 0,m = strlen(str);
    string *pointer = head;
    for(;i < m;i++){
        string *space = (string*)malloc(sizeof(string));
        pointer->word = str[i];
        pointer->next = space;
        pointer = pointer->next;
    }
    return head;
}

int compare(string *str,string *main_str){
    int i = 0,total = 0;
    string *main_pointer = main_str;

    while(main_pointer->next != NULL){

        if(main_pointer->word == str->word){
            string *str_pointer = str;
            string *main_pointer2 = main_pointer;
            while(1){
                printf("%c,%c\n",str_pointer->word,main_pointer2->word);
                if(main_pointer2->word != str_pointer->word){
                    break;
                }else if(str_pointer->next->word == '\0'){
                    total++;
                    main_pointer = main_pointer2;
                    break;
                }
                str_pointer = str_pointer->next;
                main_pointer2 = main_pointer2->next;
            }
        }

        main_pointer = main_pointer->next;
    }
    return total;
}