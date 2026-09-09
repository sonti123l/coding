#include <stdio.h>

void mergeSort(int *number_arr, int length);

int main()
{
    int size_of_arr = 0;

    printf("Enter the size: ");
    scanf("%d", &size_of_arr);

    int number_array[size_of_arr];

    printf("Enter the elements:\n");

    for (int i = 0; i < size_of_arr; i++) {
        scanf("%d", &number_array[i]);
    }

    mergeSort(number_array, size_of_arr);

    printf("Sorted array: ");

    for (int i = 0; i < size_of_arr; i++) {
        printf("%d ", number_array[i]);
    }

    printf("\n");

    return 0;
}


void mergeSort(int *number_arr, int length)
{
    
    if (length <= 1) {
        return;
    }

    int left_array_size;
    int right_array_size;

    left_array_size = (length + 1) / 2;
    right_array_size = length - left_array_size;

    int left_array_values[left_array_size];
    int right_array_values[right_array_size];

    for (int i = 0; i < left_array_size; i++) {
        left_array_values[i] = number_arr[i];
    }

    for (int i = 0; i < right_array_size; i++) {
        right_array_values[i] =
            number_arr[left_array_size + i];
    }

    mergeSort(left_array_values, left_array_size);

    mergeSort(right_array_values, right_array_size);

    int left_index = 0;
    int right_index = 0;
    int merge_index = 0;

    while (left_index < left_array_size &&
           right_index < right_array_size) {

        if (left_array_values[left_index] <=
            right_array_values[right_index]) {

            number_arr[merge_index] =
                left_array_values[left_index];

            left_index++;
        }
        else {

            number_arr[merge_index] =
                right_array_values[right_index];

            right_index++;
        }

        merge_index++;
    }

    while (left_index < left_array_size) {

        number_arr[merge_index] =
            left_array_values[left_index];

        left_index++;
        merge_index++;
    }

    while (right_index < right_array_size) {

        number_arr[merge_index] =
            right_array_values[right_index];

        right_index++;
        merge_index++;
    }
}