// My code with small logical issues -> (56/169) test cases
struct determine_character_string_count {
    char c;
    int count;
    bool beside_each_other_or_not;
};

bool closeStrings(char* word1, char* word2) {

    // first string data 
    struct determine_character_string_count *word_one_data =
        malloc(strlen(word1) * sizeof(struct determine_character_string_count));

    // second string data
    struct determine_character_string_count *word_two_data =
        malloc(strlen(word2) * sizeof(struct determine_character_string_count));

    if (word_one_data == NULL || word_two_data == NULL) {
        free(word_one_data);
        free(word_two_data);
        return false;
    }

    int first_word_data_capturing_index = 0, second_word_data_capturing_index = 0;

    // creating copies of the strings
    char copy_of_word1[strlen(word1) + 1], copy_of_word2[strlen(word2) + 1];
    strcpy(copy_of_word1, word1);
    strcpy(copy_of_word2, word2);

    if (strlen(word1) != strlen(word2)) {
        free(word_one_data);
        free(word_two_data);
        return false;
    }

    // first string data capturing
    if (word_one_data != NULL) {
        // word1 first character value entering
        for (int i = 0; i < strlen(copy_of_word1); i++) {
            word_one_data[first_word_data_capturing_index].c = copy_of_word1[0];
            word_one_data[first_word_data_capturing_index].count = 0;
            word_one_data[first_word_data_capturing_index].beside_each_other_or_not = false;

            if (word_one_data[first_word_data_capturing_index].c == copy_of_word1[i]) {
                word_one_data[first_word_data_capturing_index].count += 1;
                copy_of_word1[i] = ' ';
            }
        }

        first_word_data_capturing_index++;

        // other characters data inserting
        for (int i = 1; i < strlen(copy_of_word1); i++) {
            word_one_data[first_word_data_capturing_index].c = copy_of_word1[i];
            word_one_data[first_word_data_capturing_index].count = 0;
            word_one_data[first_word_data_capturing_index].beside_each_other_or_not = false;
            if (copy_of_word1[i] == ' ') {
                continue;
            }
            for (int j = i + 1; j < strlen(copy_of_word1); j++) {
                if (copy_of_word1[j] == ' ') {
                    continue;
                } else if (word_one_data[first_word_data_capturing_index].c == copy_of_word1[j]) {
                    word_one_data[first_word_data_capturing_index].count += 1;
                    copy_of_word1[j] = ' ';
                }
            }

            first_word_data_capturing_index++;
        }
    }

    // second string data capturing
    if (word_two_data != NULL) {
        // word1 first character value entering
        for (int i = 0; i < strlen(copy_of_word2); i++) {
            word_two_data[second_word_data_capturing_index].c = copy_of_word2[0];
            word_two_data[second_word_data_capturing_index].count = 0;
            word_two_data[second_word_data_capturing_index].beside_each_other_or_not = false;

            if (word_two_data[second_word_data_capturing_index].c == copy_of_word2[i]) {
                word_two_data[second_word_data_capturing_index].count += 1;
                copy_of_word2[i] = ' ';
            }
        }

        second_word_data_capturing_index++;

        // other characters data inserting
        for (int i = 1; i < strlen(copy_of_word2); i++) {
            word_two_data[second_word_data_capturing_index].c = copy_of_word2[i];
            word_two_data[second_word_data_capturing_index].count = 0;
            word_two_data[second_word_data_capturing_index].beside_each_other_or_not = false;

            if (copy_of_word2[i] == ' ') {
                continue;
            }

            for (int j = i + 1; j < strlen(copy_of_word2); j++) {
                if (copy_of_word2[j] == ' ') {
                    continue;
                } else if (word_two_data[second_word_data_capturing_index].c == copy_of_word2[j]) {
                    word_two_data[second_word_data_capturing_index].count += 1;
                    copy_of_word2[j] = ' ';
                }
            }

            second_word_data_capturing_index++;
        }
    }

    // if any string contains more characters then usual
    if (first_word_data_capturing_index != second_word_data_capturing_index) {
        free(word_one_data);
        free(word_two_data);
        return false;
    }

    // check if any character has more count value then other that doesn't match any of the other string data

    int count_of_each_value_occurence = 0, index = 0;
    while(first_word_data_capturing_index > index){
        for (int j = 0; j < second_word_data_capturing_index; j++) {
            if (word_one_data[index].count == word_two_data[j].count) {
                count_of_each_value_occurence++;
                break;
            }
        }
        index++;
    }

    if(count_of_each_value_occurence == first_word_data_capturing_index){
        free(word_one_data);
        free(word_two_data);
        return true;
    }

    free(word_one_data);
    free(word_two_data);
    return false;;
}

// My code after syntax errors solving -> (76/169) test cases
struct determine_character_string_count {
    char c;
    int count;
    bool beside_each_other_or_not;
};

bool closeStrings(char* word1, char* word2) {

    if (strlen(word1) != strlen(word2)) {
        return false;
    }

    // first string data
    struct determine_character_string_count *word_one_data =
        malloc(strlen(word1) * sizeof(struct determine_character_string_count));

    // second string data
    struct determine_character_string_count *word_two_data =
        malloc(strlen(word2) * sizeof(struct determine_character_string_count));

    if (strlen(word1) == 0) {
        free(word_one_data);
        free(word_two_data);
        return true;
    }

    if (word_one_data == NULL || word_two_data == NULL) {
        free(word_one_data);
        free(word_two_data);
        return false;
    }

    int first_word_data_capturing_index = 0;
    int second_word_data_capturing_index = 0;

    // creating copies of the strings
    char copy_of_word1[strlen(word1) + 1];
    char copy_of_word2[strlen(word2) + 1];

    strcpy(copy_of_word1, word1);
    strcpy(copy_of_word2, word2);

    // first string data capturing

    // word1 first character value entering
    word_one_data[first_word_data_capturing_index].c = copy_of_word1[0];
    word_one_data[first_word_data_capturing_index].count = 0;
    word_one_data[first_word_data_capturing_index].beside_each_other_or_not = false;

    for (int i = 0; i < strlen(copy_of_word1); i++) {
        if (word_one_data[first_word_data_capturing_index].c == copy_of_word1[i]) {
            word_one_data[first_word_data_capturing_index].count++;
            copy_of_word1[i] = ' ';
        }
    }

    first_word_data_capturing_index++;

    // other characters data inserting
    for (int i = 1; i < strlen(copy_of_word1); i++) {
        if (copy_of_word1[i] == ' ') {
            continue;
        }

        word_one_data[first_word_data_capturing_index].c = copy_of_word1[i];
        word_one_data[first_word_data_capturing_index].count = 1;
        word_one_data[first_word_data_capturing_index].beside_each_other_or_not = false;

        char current_character = copy_of_word1[i];
        copy_of_word1[i] = ' ';

        for (int j = i + 1; j < strlen(copy_of_word1); j++) {
            if (copy_of_word1[j] == ' ') {
                continue;
            }

            if (current_character == copy_of_word1[j]) {
                word_one_data[first_word_data_capturing_index].count++;
                copy_of_word1[j] = ' ';
            }
        }

        first_word_data_capturing_index++;
    }

    // second string data capturing

    // word2 first character value entering
    word_two_data[second_word_data_capturing_index].c = copy_of_word2[0];
    word_two_data[second_word_data_capturing_index].count = 0;
    word_two_data[second_word_data_capturing_index].beside_each_other_or_not = false;

    for (int i = 0; i < strlen(copy_of_word2); i++) {
        if (word_two_data[second_word_data_capturing_index].c == copy_of_word2[i]) {
            word_two_data[second_word_data_capturing_index].count++;
            copy_of_word2[i] = ' ';
        }
    }

    second_word_data_capturing_index++;

    // other characters data inserting
    for (int i = 1; i < strlen(copy_of_word2); i++) {
        if (copy_of_word2[i] == ' ') {
            continue;
        }

        word_two_data[second_word_data_capturing_index].c = copy_of_word2[i];
        word_two_data[second_word_data_capturing_index].count = 1;
        word_two_data[second_word_data_capturing_index].beside_each_other_or_not = false;

        char current_character = copy_of_word2[i];
        copy_of_word2[i] = ' ';

        for (int j = i + 1; j < strlen(copy_of_word2); j++) {
            if (copy_of_word2[j] == ' ') {
                continue;
            }

            if (current_character == copy_of_word2[j]) {
                word_two_data[second_word_data_capturing_index].count++;
                copy_of_word2[j] = ' ';
            }
        }

        second_word_data_capturing_index++;
    }

    // if any string contains more distinct characters than the other
    if (first_word_data_capturing_index != second_word_data_capturing_index) {
        free(word_one_data);
        free(word_two_data);
        return false;
    }

    // check whether both strings contain the same distinct characters
    for (int i = 0; i < first_word_data_capturing_index; i++) {
        bool character_found = false;

        for (int j = 0; j < second_word_data_capturing_index; j++) {
            if (word_one_data[i].c == word_two_data[j].c) {
                character_found = true;
                break;
            }
        }

        if (!character_found) {
            free(word_one_data);
            free(word_two_data);
            return false;
        }
    }

    // check whether every frequency matches a unique frequency in the other string
    for (int i = 0; i < first_word_data_capturing_index; i++) {
        bool count_found = false;

        for (int j = 0; j < second_word_data_capturing_index; j++) {
            if (word_one_data[i].count == word_two_data[j].count &&
                !word_two_data[j].beside_each_other_or_not) {

                word_two_data[j].beside_each_other_or_not = true;
                count_found = true;
                break;
            }
        }

        if (!count_found) {
            free(word_one_data);
            free(word_two_data);
            return false;
        }
    }

    free(word_one_data);
    free(word_two_data);

    return true;
}

// Third approach
struct determine_character_string_count {
    char c;
    int count;
    bool beside_each_other_or_not;
};

bool closeStrings(char* word1, char* word2) {

    if (strlen(word1) != strlen(word2)) {
        return false;
    }

    // first string data
    struct determine_character_string_count *word_one_data =
        malloc(strlen(word1) * sizeof(struct determine_character_string_count));

    // second string data
    struct determine_character_string_count *word_two_data =
        malloc(strlen(word2) * sizeof(struct determine_character_string_count));

    if (strlen(word1) == 0) {
        free(word_one_data);
        free(word_two_data);
        return true;
    }

    if (word_one_data == NULL || word_two_data == NULL) {
        free(word_one_data);
        free(word_two_data);
        return false;
    }

    int first_word_data_capturing_index = 0;
    int second_word_data_capturing_index = 0;

    // creating copies of the strings
    char copy_of_word1[strlen(word1) + 1];
    char copy_of_word2[strlen(word2) + 1];

    strcpy(copy_of_word1, word1);
    strcpy(copy_of_word2, word2);

    // first string data capturing

    // word1 first character value entering
    word_one_data[first_word_data_capturing_index].c = copy_of_word1[0];
    word_one_data[first_word_data_capturing_index].count = 0;
    word_one_data[first_word_data_capturing_index].beside_each_other_or_not = false;

    for (int i = 0; i < strlen(copy_of_word1); i++) {
        if (word_one_data[first_word_data_capturing_index].c == copy_of_word1[i]) {
            word_one_data[first_word_data_capturing_index].count++;
            copy_of_word1[i] = ' ';
        }
    }

    first_word_data_capturing_index++;

    // other characters data inserting
    for (int i = 1; i < strlen(copy_of_word1); i++) {
        if (copy_of_word1[i] == ' ') {
            continue;
        }

        word_one_data[first_word_data_capturing_index].c = copy_of_word1[i];
        word_one_data[first_word_data_capturing_index].count = 1;
        word_one_data[first_word_data_capturing_index].beside_each_other_or_not = false;

        char current_character = copy_of_word1[i];
        copy_of_word1[i] = ' ';

        for (int j = i + 1; j < strlen(copy_of_word1); j++) {
            if (copy_of_word1[j] == ' ') {
                continue;
            }

            if (current_character == copy_of_word1[j]) {
                word_one_data[first_word_data_capturing_index].count++;
                copy_of_word1[j] = ' ';
            }
        }

        first_word_data_capturing_index++;
    }

    // second string data capturing

    // word2 first character value entering
    word_two_data[second_word_data_capturing_index].c = copy_of_word2[0];
    word_two_data[second_word_data_capturing_index].count = 0;
    word_two_data[second_word_data_capturing_index].beside_each_other_or_not = false;

    for (int i = 0; i < strlen(copy_of_word2); i++) {
        if (word_two_data[second_word_data_capturing_index].c == copy_of_word2[i]) {
            word_two_data[second_word_data_capturing_index].count++;
            copy_of_word2[i] = ' ';
        }
    }

    second_word_data_capturing_index++;

    // other characters data inserting
    for (int i = 1; i < strlen(copy_of_word2); i++) {
        if (copy_of_word2[i] == ' ') {
            continue;
        }

        word_two_data[second_word_data_capturing_index].c = copy_of_word2[i];
        word_two_data[second_word_data_capturing_index].count = 1;
        word_two_data[second_word_data_capturing_index].beside_each_other_or_not = false;

        char current_character = copy_of_word2[i];
        copy_of_word2[i] = ' ';

        for (int j = i + 1; j < strlen(copy_of_word2); j++) {
            if (copy_of_word2[j] == ' ') {
                continue;
            }

            if (current_character == copy_of_word2[j]) {
                word_two_data[second_word_data_capturing_index].count++;
                copy_of_word2[j] = ' ';
            }
        }

        second_word_data_capturing_index++;
    }

    // if any string contains more distinct characters than the other
    if (first_word_data_capturing_index != second_word_data_capturing_index) {
        free(word_one_data);
        free(word_two_data);
        return false;
    }

    // check whether both strings contain the same distinct characters
    for (int i = 0; i < first_word_data_capturing_index; i++) {
        bool character_found = false;

        for (int j = 0; j < second_word_data_capturing_index; j++) {
            if (word_one_data[i].c == word_two_data[j].c) {
                character_found = true;
                break;
            }
        }

        if (!character_found) {
            free(word_one_data);
            free(word_two_data);
            return false;
        }
    }

    // check whether every frequency matches a unique frequency in the other string
    for (int i = 0; i < first_word_data_capturing_index; i++) {
        bool count_found = false;

        for (int j = 0; j < second_word_data_capturing_index; j++) {
            if (word_one_data[i].count == word_two_data[j].count &&
                !word_two_data[j].beside_each_other_or_not) {

                word_two_data[j].beside_each_other_or_not = true;
                count_found = true;
                break;
            }
        }

        if (!count_found) {
            free(word_one_data);
            free(word_two_data);
            return false;
        }
    }

    free(word_one_data);
    free(word_two_data);

    return true;
}