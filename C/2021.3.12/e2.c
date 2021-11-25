#include <stdio.h>
#include <math.h>
int main(){
    float a = 1.23856,c;
    int b;
    b = fabs(a * 100 + 0.5);
    c = b/100.0;
    printf("%f",c);
    return 0;
}