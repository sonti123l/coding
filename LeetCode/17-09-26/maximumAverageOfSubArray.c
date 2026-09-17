double findMaxAverage(int* nums, int numsSize, int k) {

    double sum = 0;
    double max_average;

    int index = 0;
    int iterate_index = k - 1;

    for(int i = 0; i < k; i++){
        sum += nums[i];
    }

    max_average = sum / k;

    while(iterate_index + 1 < numsSize){

        sum = sum - nums[index] + nums[iterate_index + 1];

        double average = sum / k;

        if(average > max_average){
            max_average = average;
        }

        index++;
        iterate_index++;
    }

    return max_average;
}