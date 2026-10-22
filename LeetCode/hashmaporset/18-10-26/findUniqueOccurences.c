// My First approach ----> 49/78 test cases passed
bool uniqueOccurrences(int* arr, int arrSize) {
    int previous_occurence_count = 0, first_element = arr[0], non_first_element_occurence_index = 0, count = 0;

    if(arrSize == 2){
        if(arr[0] == arr[1]){
            return true;
        }else{
            return false;
        }
    }

    for(int i = 0; i < arrSize; i++){
        if(first_element == arr[i]){
            previous_occurence_count++;
        }else if(first_element != arr[i]){
            if(!non_first_element_occurence_index){
                non_first_element_occurence_index = i;
            }
        }
    }

    for(int i = non_first_element_occurence_index; i < arrSize; i++){
        count += 1;
        for(int j = i+1; j < arrSize; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }

        if(previous_occurence_count == count){
            if(i+1 != arrSize){
                return false;
            }
            return true;
        }else{
            printf("previous occurence count value: %d current element occurence count: %d\n", previous_occurence_count, count);
            previous_occurence_count = count;
            count = 0;
        }
    }

    return true;
}

// My Second appraoch -> 66 test cases 
bool uniqueOccurrences(int* arr, int arrSize) {
    
    int first_element = arr[0], previous_occurence_count = 0;
    
    for(int i = 0; i < arrSize; i++){
        if(first_element == arr[i]){
            previous_occurence_count++;
        }
    }

    int remaining_elements_length = arrSize - previous_occurence_count;
    int *remaining_elements_array = malloc(remaining_elements_length * sizeof(int)), index = 0;

    if(remaining_elements_length == 0){
        return true;
    }

    for(int i = 0; i < arrSize; i++){
        if(first_element != arr[i]){
            remaining_elements_array[index] = arr[i];
            index++;
        }
    }


    while(remaining_elements_length > 0){
        first_element = remaining_elements_array[0];
        int count = 0, new_index = 0;

        for(int i = 0; i < index; i++){
            if(first_element == remaining_elements_array[i]){
                count++;
            }
        }

        if(count == previous_occurence_count){
            return false;
        }

        remaining_elements_length = remaining_elements_length - count;
        int *new_remaining_elements = malloc(remaining_elements_length * sizeof(int));

        for(int i = 0; i < index; i++){
            if(first_element != remaining_elements_array[i]){
                new_remaining_elements[new_index] = remaining_elements_array[i];
                new_index++;
            }
        }
        
        free(remaining_elements_array);
        remaining_elements_array = new_remaining_elements;
        index = new_index;
    }

    if(remaining_elements_length == 0){
        return true;
    }

    return false;
}

// My code fixed section

#include <stdlib.h>
#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    if (arrSize == 0) {
        return true;
    }

    int first_element = arr[0], previous_occurrence_count = 0;

    for (int i = 0; i < arrSize; i++) {
        if (first_element == arr[i]) {
            previous_occurrence_count++;
        }
    }

    int remaining_elements_length = arrSize - previous_occurrence_count;

    int *remaining_elements_array = malloc(remaining_elements_length * sizeof(int));
    int index = 0;

    if (remaining_elements_length > 0 && remaining_elements_array == NULL) {
        return false;
    }

    for (int i = 0; i < arrSize; i++) {
        if (first_element != arr[i]) {
            remaining_elements_array[index++] = arr[i];
        }
    }

    int *frequencies = malloc(arrSize * sizeof(int));
    if (frequencies == NULL) {
        free(remaining_elements_array);
        return false;
    }

    int frequency_count = 0;
    frequencies[frequency_count++] = previous_occurrence_count;

    while (remaining_elements_length > 0) {
        first_element = remaining_elements_array[0];

        int count = 0, new_index = 0;

        for (int i = 0; i < index; i++) {
            if (first_element == remaining_elements_array[i]) {
                count++;
            }
        }

        for (int i = 0; i < frequency_count; i++) {
            if (frequencies[i] == count) {
                free(frequencies);
                free(remaining_elements_array);
                return false;
            }
        }

        frequencies[frequency_count++] = count;

        remaining_elements_length -= count;

        int *new_remaining_elements = NULL;

        if (remaining_elements_length > 0) {
            new_remaining_elements = malloc(remaining_elements_length * sizeof(int));

            if (new_remaining_elements == NULL) {
                free(frequencies);
                free(remaining_elements_array);
                return false;
            }
        }

        for (int i = 0; i < index; i++) {
            if (first_element != remaining_elements_array[i]) {
                new_remaining_elements[new_index++] = remaining_elements_array[i];
            }
        }

        free(remaining_elements_array);
        remaining_elements_array = new_remaining_elements;
        index = new_index;
    }

    free(frequencies);
    free(remaining_elements_array);

    return true;
}
