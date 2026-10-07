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

    char *expression = malloc(size + 1);

    if (expression == NULL) {
        return 1;
    }

    for (int i = 0; i < size; i++) {
        scanf(" %c", &expression[i]);
    }

    expression[size] = '\0';

    is_balanced_string_or_not =
        check_expression_is_valid_or_not(expression);

    if (is_balanced_string_or_not) {
        printf("balance string");
    } else {
        printf("not balanced string");
    }

    free(expression);

    return 0;
}

bool check_expression_is_valid_or_not(char *s)
{
    char *inserting_string = malloc(strlen(s) + 1);

    if (inserting_string == NULL) {
        return false;
    }

    int index = 0;
    int present_element_index = 0;
    int length = strlen(s);

    bool check_operator_expression = true;

    if (length == 0) {
        free(inserting_string);
        return false;
    }

    while (s[present_element_index]) {


        if (isalpha(s[present_element_index])) {

            if (check_operator_expression == false) {
                free(inserting_string);
                return false;
            }

            check_operator_expression = false;
            present_element_index++;
        }

        else if (s[present_element_index] == '{' ||
                 s[present_element_index] == '(' ||
                 s[present_element_index] == '[') {

            if (check_operator_expression == false) {
                free(inserting_string);
                return false;
            }

            inserting_string[index] = s[present_element_index];
            index++;

            check_operator_expression = true;

            present_element_index++;
        }

        else if (s[present_element_index] == '}' ||
                 s[present_element_index] == ')' ||
                 s[present_element_index] == ']') {

            if (check_operator_expression == true) {
                free(inserting_string);
                return false;
            }

            if (index == 0) {
                free(inserting_string);
                return false;
            }

            index--;

            if (s[present_element_index] == '}' &&
                inserting_string[index] != '{') {

                free(inserting_string);
                return false;
            }

            if (s[present_element_index] == ')' &&
                inserting_string[index] != '(') {

                free(inserting_string);
                return false;
            }

            if (s[present_element_index] == ']' &&
                inserting_string[index] != '[') {

                free(inserting_string);
                return false;
            }


            check_operator_expression = false;

            present_element_index++;
        }

        else if (s[present_element_index] == '+' ||
                 s[present_element_index] == '-' ||
                 s[present_element_index] == '*' ||
                 s[present_element_index] == '%' ||
                 s[present_element_index] == '/') {

            if (check_operator_expression == true) {
                free(inserting_string);
                return false;
            }

            check_operator_expression = true;

            present_element_index++;
        }


        else {

            free(inserting_string);
            return false;
        }
    }


    if (check_operator_expression == true) {
        free(inserting_string);
        return false;
    }

    if (index != 0) {
        free(inserting_string);
        return false;
    }

    free(inserting_string);

    return true;
}