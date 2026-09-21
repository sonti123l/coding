// This is my appoarch
int longestOnes(int* nums, int numsSize, int k) {

    int max_count_of_ones = 0, calculate_index = 0;

    while(calculate_index < numsSize){

        int count = 0;

        for(int i=calculate_index; i < numsSize; i++){
            if(nums[i] == 1){
                count += 1;
            }else{
                if(k != 0){
                    nums[i] = 1;
                    k -= 1;
                    count += 1;
                }else{
                    break;
                }
            }
        }

        if(count > max_count_of_ones){
            max_count_of_ones = count;
            k = 1;
        }

        calculate_index++;
    }

    return max_count_of_ones;
}

// my code approach changed ---> but more time complexity
int longestOnes(int* nums, int numsSize, int k) {

    int max_count_of_ones = 0;

    for (int start = 0; start < numsSize; start++) {

        int count = 0;
        int zero_count = 0;

        for (int i = start; i < numsSize; i++) {

            if (nums[i] == 1) {
                count++;
            } else {
                zero_count++;

                if (zero_count > k) {
                    break;
                }

                count++;
            }
        }

        if (count > max_count_of_ones) {
            max_count_of_ones = count;
        }
    }

    return max_count_of_ones;
}

// chatgpt approach
int longestOnes(int* nums, int numsSize, int k) {

    int left = 0;
    int zero_count = 0;
    int max_length = 0;

    for (int right = 0; right < numsSize; right++) {

        if (nums[right] == 0) {
            zero_count++;
        }

        while (zero_count > k) {

            if (nums[left] == 0) {
                zero_count--;
            }

            left++;
        }

        int current_length = right - left + 1;

        if (current_length > max_length) {
            max_length = current_length;
        }
    }

    return max_length;
}