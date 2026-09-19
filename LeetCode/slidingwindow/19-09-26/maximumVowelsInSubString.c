// This is my appoarch where timelimit is exceeds 
int maxVowels(char* s, int k) 
{

    int count_vowels_in_sub_string = 0, loop_value = k, calculate_vowel_counts = 0;

    char vowel_characters[6] = "aeiou";

   for (int index = 0; index <= strlen(s) - k; index++) {      

    calculate_vowel_counts = 0;

    for (int i = index; i < index + k; i++) {               

            for (int j = 0; j < strlen(vowel_characters); j++) { 

                if (s[i] == vowel_characters[j]) {
                    calculate_vowel_counts++;
                }
            }
        }

        if (calculate_vowel_counts > count_vowels_in_sub_string) {
            count_vowels_in_sub_string = calculate_vowel_counts;
        }
    }

    return count_vowels_in_sub_string;
}


// this is my second approach 
int maxVowels(char* s, int k)
{
    char vowel_characters[6] = "aeiou";
    int count_vowels = 0;
    int max_vowels = 0;
    int length = strlen(s);

    // First window: s[0 ... k-1]
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 5; j++) {
            if (s[i] == vowel_characters[j]) {
                count_vowels++;
                break;
            }
        }
    }

    max_vowels = count_vowels;

    // Slide the window
    for (int i = k; i < length; i++) {

        // Remove the character leaving the window
        for (int j = 0; j < 5; j++) {
            if (s[i - k] == vowel_characters[j]) {
                count_vowels--;
                break;
            }
        }

        // Add the new character entering the window
        for (int j = 0; j < 5; j++) {
            if (s[i] == vowel_characters[j]) {
                count_vowels++;
                break;
            }
        }

        if (count_vowels > max_vowels) {
            max_vowels = count_vowels;
        }
    }

    return max_vowels;
}