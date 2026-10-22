int pivotIndex(int* nums, int numsSize) {
    int left_sum = 0, right_sum = 0, pivot_index = 0;

    while(pivot_index < numsSize){
        if(pivot_index == 0){
            left_sum =0;
            for(int i = pivot_index+1; i< numsSize; i++){
                right_sum = right_sum + nums[i];
            }
        }else{

            if(pivot_index != numsSize){
                for(int i = 0; i < pivot_index; i++){
                    left_sum = left_sum + nums[i];
                }

                for(int j = pivot_index+1; j < numsSize; j++){
                    right_sum = right_sum + nums[j];
                }
            }else{
                right_sum = 0;
                for(int i = 0; i < pivot_index; i++){
                    left_sum = left_sum + nums[i];
                }
            }
        }

        if(left_sum == right_sum){
            return pivot_index;
        }
        pivot_index++;
        left_sum = 0;
        right_sum = 0;
    }

    return -1;
    
}