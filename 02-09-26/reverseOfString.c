// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "hello";
    char str_one[strlen(str) + 1];
    int index = 0;
    for(int i = strlen(str)-1; i >= 0; i--){
        str_one[index] = str[i];
        index++;
    }
    str_one[index] = '\0';

    printf("%s", str_one);
}