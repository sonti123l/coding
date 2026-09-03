#include<stdio.h>

void findTwoSingleNumbers(int arr[], int n, int *out1, int *out2);

int main(){
    int number_arr[6] = {1, 2, 1, 3, 2, 5};
    int arr_length = sizeof(number_arr)/sizeof(number_arr[0]);
    int output1 = 0;
    int output2 = 0;

    findTwoSingleNumbers(number_arr, arr_length, &output1, &output2);

    return 0;

}

void findTwoSingleNumbers(int arr[], int n, int *out1, int *out2){
    int count = 0;
    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if((arr[i] & ~arr[j]) == 0){
                count += 1;
            }
        }
        if(count == 1){
            if(*out1 == 0){
                *out1 = arr[i];
            }else{
                *out2 = arr[i];
            }
        }
    }

    printf("%d %d", *out1, *out2);
}