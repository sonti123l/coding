#include<stdio.h>
#include<string.h>
void getCharacterData(char *oneChar);


int main(){
    char stringCharacter;
    printf("Enter the character \n");
    scanf("%c", &stringCharacter);

    getCharacterData(&stringCharacter);
}

void getCharacterData(char *oneChar){

    char *ptr = oneChar;
    if((97 <= *ptr) && (*ptr<= 128)){
        printf("the character %c is lower case \n", *ptr);
        printf("The value is: %d\n", *ptr);
    }else{
        printf("the character %c is upper case\n", *ptr);
        printf("The value is: %d\n", *ptr);
    }
}
