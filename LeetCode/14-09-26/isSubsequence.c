//first appoarch

// bool isSubsequence(char* s, char* t) {
//     int first_index = 0, index = 0;
//     char *new = malloc(strlen(s)+1);
//     if(new != NULL){
//         for(int i =0; i< strlen(t); i++){
//             if(t[i] != s[index]){
//                 t[i] = ' ';
//             }else{
//                 index++;
//             }
//         }

//         index = 0;
//         for(int i = 0; i<strlen(t); i++){
//             if(t[i] != ' '){
//                 new[index] = t[i];
//                 index++;
//             }
//         }

//         new[index] = '\0';

//         if(!strcmp(new, s)){
//             return true;
//         }
//     }
//     return false;
    
// }

// second approach

bool isSubsequence(char* s, char* t) {
    int index = 0, count = 0;

    for(int i =0; i< strlen(t); i++){
        if(t[i] != s[index]){
            t[i] = ' ';
        }else{
            index++;
        }
    }

    for(int i = 0; i< strlen(t); i++){
        if(index == 0 && t[i] == s[count]){
            index = i;
            count++;
            continue;
        }

        if(t[i] == s[count] && index < i){
            index = i;
            count++;
            continue;
        }
    }

    if(count == strlen(s)){
        return true;
    }

    return false;
    
}