char* reverseWords(char* s) {
    int count = 0;
    int index = 0;
    int word_index = 0;

    int length = strlen(s);

    // Count words
    for (int i = 0; i < length; i++) {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            count++;
        }
    }

    char words_array[count][100];

    char *words = malloc(length + 1);

    if (words == NULL) {
        return NULL;
    }

    // Store words
    for (int j = 0; j < length; j++) {

        if (s[j] == ' ') {

            if (index > 0) {
                words_array[word_index][index] = '\0';
                word_index++;
                index = 0;
            }

        } else {

            words_array[word_index][index] = s[j];
            index++;
        }
    }

    if (index > 0) {
        words_array[word_index][index] = '\0';
    }

    int result_index = 0;

    for (int k = count - 1; k >= 0; k--) {

        for (int z = 0; z < strlen(words_array[k]); z++) {
            words[result_index] = words_array[k][z];
            result_index++;
        }

        if (k != 0) {
            words[result_index] = ' ';
            result_index++;
        }
    }

    words[result_index] = '\0';

    return words;
}