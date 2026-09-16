int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maxOperations(int* nums, int numsSize, int k){

    qsort(nums, numsSize, sizeof(int), compare);
    int left = 0, right = numsSize - 1,  sum = 0, count = 0;

    while(left < right){

        sum = nums[left] + nums[right];
        
        if(sum == k){
            nums[left] = 0;
            nums[right] = 0;
            count += 1;
            left++;
            right--;
        }else if(sum > k){
            right--;
        }else{
            left++;
        }

    }

    return count;
}