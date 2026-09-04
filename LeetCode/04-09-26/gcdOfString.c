#include <string.h>
#include <stdlib.h>

char *gcdOfStrings(char *str1, char *str2)
{
    int sum_of_characters_of_first_string = 0, sum_of_characters_of_second_string = 0, first_string_division_result = 0, second_string_division_result = 0, count = strlen(str2);
    char *first_occurence = malloc(strlen(str2) + 2);
    if (first_occurence == NULL)
    {
        return '\0';
    }
    for (int i = 0; i < strlen(str1); i++)
    {
        sum_of_characters_of_first_string = sum_of_characters_of_first_string + str1[i];
    }

    for (int i = 0; i < strlen(str2); i++)
    {
        sum_of_characters_of_second_string = sum_of_characters_of_second_string + str2[i];
    }

    while (count > 0)
    {
        int dividing_characters_sum = 0;
        for (int i = 0; i < count; i++)
        {
            dividing_characters_sum = dividing_characters_sum + str2[i];
        }

        first_string_division_result = sum_of_characters_of_first_string % dividing_characters_sum;
        second_string_division_result = sum_of_characters_of_second_string % dividing_characters_sum;

        if (!first_string_division_result && !second_string_division_result)
        {
            for (int k = 0; k < count; k++)
            {
                first_occurence[k] = str2[k];
            }
            first_occurence[count] = '\0';
            return first_occurence;
        }

        count = count - 1;
    }

    first_occurence[0] = '\0';
    return first_occurence;
}