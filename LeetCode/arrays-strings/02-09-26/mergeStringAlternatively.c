#include<string.h>
#include <stdlib.h>

char * mergeAlternately(char * word1, char * word2){
    int index = 0, temp_index = 0;
    char *mergeString = malloc(strlen(word1) + strlen(word2) + 1);
    if(strlen(word1) == strlen(word2)){
        for(int i = 0; i < strlen(word1); i++){
            mergeString[index] = word1[i];
            index = index + 1;
            if(index % 2 == 1){
                mergeString[index] = word2[i];
                index = index + 1;
            }
        }
    }else if(strlen(word1) < strlen(word2)){
        for(int i = 0; i < strlen(word1); i++){
            mergeString[index] = word1[i];
            index = index + 1;
            if(index % 2 == 1){
                mergeString[index] = word2[i];
                index = index + 1;
            }
            temp_index = i+1;
        }
        for(int j = temp_index ; j < strlen(word2); j++){
            mergeString[index] = word2[j];
            index = index + 1;
        }
    }else{
        for(int i = 0; i < strlen(word2); i++){
            mergeString[index] = word1[i];
            index = index + 1;
            if(index % 2 == 1){
                mergeString[index] = word2[i];
                index = index + 1;
            }
            temp_index = i+1;
        }
        for(int j = temp_index ; j < strlen(word1); j++){
            mergeString[index] = word1[j];
            index = index + 1;
        }
    }
    mergeString[index] = '\0';
    return mergeString;
}