struct dataPoint{
    char vowel;
    int vowel_index;
};

char* reverseVowels(char* s) {
    int index = 0;
    char vowels[11] = "AEIOUaeiou";
    char temp;
    struct dataPoint *getVowelCharacters = malloc(strlen(s)*sizeof(struct dataPoint));
    if(getVowelCharacters != NULL){
        for(int i = 0; i < strlen(s); i++){
            for(int j = 0; j < strlen(vowels); j++){
                if(s[i] == vowels[j]){
                    getVowelCharacters[index].vowel = s[i];
                    getVowelCharacters[index].vowel_index = i;
                    index = index + 1;
                }
            }
        }
        for(int i = 0; i < index/2; i++){
            temp = getVowelCharacters[i].vowel;
            getVowelCharacters[i].vowel = getVowelCharacters[index-1 - i].vowel;
            getVowelCharacters[index-1-i].vowel = temp;
        }

        for(int j = 0; j < index; j++){
            s[getVowelCharacters[j].vowel_index] = getVowelCharacters[j].vowel;
        }
        free(getVowelCharacters);
    }
    return s;
}