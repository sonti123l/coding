// First approach
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    int *number_product = malloc(numsSize * sizeof(int));

    if (number_product == NULL)
    {
        return NULL;
    }

    int product = 1;

    for (int i = 0; i < numsSize; i++)
    {
        number_product[i] = product;
        product = product * nums[i];
    }

    product = 1;

    for (int i = numsSize - 1; i >= 0; i--)
    {
        number_product[i] = number_product[i] * product;
        product = product * nums[i];
    }

    return number_product;
}

// second approach
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;

    int flag = 0, count_no_of_zeroes = 0, first_zero_index = 0, temp = 1;

    int *result = malloc(numsSize*sizeof(int));

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            if(first_zero_index == 0){
                first_zero_index = i;
            }
            count_no_of_zeroes++;
            flag = 1;
        }
    }


    if(count_no_of_zeroes > 1){
        for(int i = 0; i < numsSize; i++){
            result[i] = 0;
        }
    }else if(count_no_of_zeroes == 1){
        for(int i = 0; i < numsSize; i++){
            if(nums[i] == 0){
                continue;
            }
            temp = temp*nums[i];
        }

        if(flag == 1)
        {
            for(int i = 0; i < numsSize; i++){
                if(first_zero_index != i){
                    result[i] = 0;
                }else{
                    result[i] = temp;
                }
            }
        }
    }else{
        for(int i = 0; i < numsSize; i++){
            temp = temp*nums[i];
        }

        for(int i = 0; i < numsSize; i++){
            result[i] = temp/nums[i];
        }
    }

    return result;
    
}
