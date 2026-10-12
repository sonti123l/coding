int largestAltitude(int* gain, int gainSize) {
    int maximum_altitude_value = 0;

    int new_gain_size[gainSize+1];

    new_gain_size[0] = 0;
    for(int i = 1; i < gainSize+1; i++){
        new_gain_size[i] = new_gain_size[i-1] + gain[i-1];
        if(maximum_altitude_value < new_gain_size[i]){
            maximum_altitude_value = new_gain_size[i];
        }
    }

    return maximum_altitude_value;
}