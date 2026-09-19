#include<stdio.h>

int firstMissingPositive(int *nums, int numsSize);

int main(){
    
    int nums_list[5] = {1, 2, 3, 4, 6};

    int length = sizeof(nums_list)/sizeof(nums_list[0]);
    firstMissingPositive(nums_list, length);
    return 0;
}

// int firstMissingPositive(int* nums, int numsSize) {
//     for(int i = 0; i < numsSize; i++){
//         while(nums[i]>=1 && nums[i]<=numsSize && nums[i] != nums[nums[i]-1]){
//             int temp = nums[i];
//             nums[i] = nums[nums[i]-1];
//             nums[temp-1] = temp;
//         }
//     }
//     for(int i = 0; i<numsSize; i++){
//         if(nums[i] != i+1){
//             return i+1;
//         }
//     }

//     return numsSize+1;
// }

int firstMissingPositive(int* nums, int numsSize) {
    int number = 1;
    while(1){
        for(int i = 0; i < numsSize; i++){
            if(nums[i] <= 0 || nums[i] != number){
                continue;
            }else{
               i=-1;
               number = number+1;
            }
        }
        break;
    }
    return number;
}