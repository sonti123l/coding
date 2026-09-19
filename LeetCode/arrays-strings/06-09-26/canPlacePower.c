bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    bool is_fitted_or_not = false;
    int previous_record = 0, iterate_index = 1, index = 0;
    while((n > 0)){
        for(int i = index; (i < iterate_index) && (iterate_index != flowerbedSize); i++){
            if(flowerbed[i] == 1){
                previous_record = 1;
                is_fitted_or_not = false;
            }else{
                if(previous_record){
                    is_fitted_or_not = false;
                    previous_record = 0;
                }else{
                    flowerbed[i] = 1;
                    previous_record = 1;
                    is_fitted_or_not = true;
                    if((n-1) == 0){
                        break;
                    }
                }
            }
            index = index+1;
            iterate_index = iterate_index + 1;
        }
        n = n-1;
        iterate_index = 2;
    }
    return is_fitted_or_not;
}