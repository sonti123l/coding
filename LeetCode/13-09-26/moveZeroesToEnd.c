void moveZeroes(int* nums, int numsSize) {

    int temp = 0, count = 0, first_zero_index = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0 && count == 0){
            first_zero_index = i;
            count += 1;
        }

        if(nums[i] != 0){
            temp = nums[i];
            nums[i] = nums[first_zero_index];
            nums[first_zero_index] = temp;
            first_zero_index++;
        }
    }
}