int compress(char* chars, int charsSize) {
    char previous_char = chars[0];
    int count = 1, index = 0;
    char new_string_array[charsSize + 1];

    if (charsSize == 1) {
        return 1;
    }

    for (int i = 1; i < charsSize; i++) {

        if (previous_char == chars[i]) {
            count++;
        } else {
            new_string_array[index++] = previous_char;

            if (count > 1) {
                int divisor = 1;
                int temp = count;

                while (temp >= 10) {
                    divisor *= 10;
                    temp /= 10;
                }

                while (divisor > 0) {
                    new_string_array[index++] = (count / divisor) + '0';
                    count = count - ((count / divisor) * divisor);
                    divisor /= 10;
                }
            }

            previous_char = chars[i];
            count = 1;
        }
    }

    new_string_array[index++] = previous_char;

    if (count > 1) {
        int divisor = 1;
        int temp = count;

        while (temp >= 10) {
            divisor *= 10;
            temp /= 10;
        }

        while (divisor > 0) {
            new_string_array[index++] = (count / divisor) + '0';
            count = count - ((count / divisor) * divisor);
            divisor /= 10;
        }
    }

    for (int i = 0; i < index; i++) {
        chars[i] = new_string_array[i];
    }

    return index;
}