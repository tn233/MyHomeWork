#include <stdio.h>
#include <string.h>

struct struct3
{
    char key[100];
    char value[100];
} *a;

int main(){
    *a->key = "happy";
    *a->value = "apple";
    printf("%s",*a->key);
    return 0;
}
