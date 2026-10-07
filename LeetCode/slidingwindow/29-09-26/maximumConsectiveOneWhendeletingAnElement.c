int longestSubarray(int* nums, int numsSize) {

    int count = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            count += 1;
        }
    }

    if(count == 1 || count == 0){
        return numsSize - 1;
    }

    int zero_index[count];
    count = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            zero_index[count] = i;
            count++;
        }
    }

    int max_count = 0;

    for(int i = 0; i < count; i++){

        int max = 0;

        if(i == 0){

            if(zero_index[i] == 0){
                max = zero_index[i + 1] - zero_index[i] - 1;
            }else{
                max = zero_index[i];
            }

        }else if(i == count - 1){

            if(zero_index[i] - zero_index[i - 1] == 1){
                max = numsSize - zero_index[i] - 1;
            }else{
                max = (zero_index[i] - zero_index[i - 1] - 1)
                    + (numsSize - zero_index[i] - 1);
            }

        }else{

            if(zero_index[i] - zero_index[i - 1] == 1){

                max = zero_index[i + 1] - zero_index[i] - 1;

            }else if(zero_index[i + 1] - zero_index[i] == 1){

                max = zero_index[i] - zero_index[i - 1] - 1;

            }else{

                max = (zero_index[i] - zero_index[i - 1] - 1)
                    + (zero_index[i + 1] - zero_index[i] - 1);
            }
        }

        if(max > max_count){
            max_count = max;
        }
    }

    return max_count;
}