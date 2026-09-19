int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int area = 0;

    while(left < right) {
        int current_area;

        if(height[left] < height[right]) {
            current_area = (right - left) * height[left];
            left++;
        } else {
            current_area = (right - left) * height[right];
            right--;
        }

        if(current_area > area) {
            area = current_area;
        }
    }

    return area;