#include<stdio.h>

void main(){
    int no_of_elements;
    printf("Enter the number \n");
    scanf("%d", &no_of_elements);
    int sum = 0;
    int chances[no_of_elements];

    for(int i = 1; i <= no_of_elements; i++){
        sum = sum + i;
        chances[i-1] = i;
    }

    int numbers_arr[sum];
    int index = 0;
    for(int i = sum; i > 0; i--){
        numbers_arr[index] = i;
        index++;
    }

    for(int i = 0; i <=sum; i++){
        int previous_index = i;
        while(chances[i] != previous_index ){
            printf("%d", numbers_arr[i]);
            chances[i] = chances[i] - 1;
        }
        printf("\n");
    }


}