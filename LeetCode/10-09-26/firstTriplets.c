bool increasingTriplet(int* nums, int numsSize) {
    int consecutive_index = 0;
    int consecutive_array_index[3];

    if (numsSize < 3) {
        return false;
    }

    for (int i = 0; i < numsSize; i++) {
        if (consecutive_index == 0 || nums[i] > consecutive_array_index[consecutive_index - 1]) {
            consecutive_array_index[consecutive_index] = nums[i];
            consecutive_index++;
            if (consecutive_index == 3) return true;
        }
        else {
            for (int j = 0; j < consecutive_index; j++) {
                if (nums[i] <= consecutive_array_index[j]) {
                    consecutive_array_index[j] = nums[i];
                    break;
                }
            }
        }
    }

    return false;
}