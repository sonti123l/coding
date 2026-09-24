#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool check_expression_is_valid_or_not(char *s);

int main()
{
    int size;
    bool is_balanced_string_or_not = false;
    printf("Enter the size: ");
    scanf("%d", &size);
    
    char *expression = malloc(size+1);
    
    for(int i=0; i<size; i++){
        scanf(" %c", &expression[i]);
    }
    
    expression[size] = '\0';
    
    is_balanced_string_or_not = check_expression_is_valid_or_not(expression);
    
    if(is_balanced_string_or_not){
        printf("balance string");
    }else{
        printf("not balanced string");
    }
    
    free(expression);

    return 0;
}

bool check_expression_is_valid_or_not(char *s){
    
    char *inserting_string = malloc(strlen(s)+1);
    int index = 0, present_element_index = 0, length = strlen(s);
    int count_an_opertor_expression = 0;
    
    if(length == 1 && isalpha(s[length-1])){
        return true;
    }
    
    if(length == 1){
        return false;
    }
    
    if(s[length-1] == '{' || s[length-1] == '[' || s[length-1] == '('){
        return false;
    }
    
    while(s[present_element_index]){
        if(s[present_element_index] == '{' || s[present_element_index] == '(' || s[present_element_index] == '['){
            inserting_string[index] = s[present_element_index];
            index++;
            present_element_index++;
        }
        
        if(s[present_element_index] == '}'){
            index--;
            if(inserting_string[index] != '{'){
                break;
            }
        }else if(s[present_element_index] == ')'){
            index--;
            if(inserting_string[index] != '('){
                break;
            }
        }else if(s[present_element_index] == ']'){
            index--;
            if(inserting_string[index] != '['){
                break;
            }
        }
        
        present_element_index++;
    }
    
    free(inserting_string);
    
    if(index != 0){
        return false;
    }
    
    return true;

}