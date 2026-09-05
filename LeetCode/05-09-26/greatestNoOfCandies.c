/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stdlib.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;
    bool *check_greatest_or_not = malloc((*returnSize) * sizeof(bool));
    int is_max = 0, sum_of_each_candy = 0;
    if(check_greatest_or_not != NULL){
        for(int i = 0; i < candiesSize; i++){
            sum_of_each_candy = extraCandies + candies[i];
            
            for(int j = 0; j < candiesSize; j++){
                if(sum_of_each_candy >= candies[j]){
                    is_max = is_max + 1;
                }
            }

            if(is_max == candiesSize){
                check_greatest_or_not[i] = true;
            }else{
                check_greatest_or_not[i] = false;
            }

            is_max = 0;
        } 
    }
    return check_greatest_or_not;
}