/**
 * Given n non-negative integers representing an elevation map where
 * the width of each bar is 1, compute how much water it is able to
 * trap after raining.
 */

int trap(int* height, int heightSize) {
    if (heightSize < 3) return 0;
    int i, rain, idx, curr, temp;
    rain = 0;
    idx = temp = 0;
    curr = 0;
    for (i = 1; i < heightSize; i++) {
        if (height[i] < height[temp]) {
            curr += (height[temp] - height[i]);
        } else {
            temp = i;
            rain += curr;
            curr = 0;
        }
    }
    idx = temp;
    temp = heightSize - 1;
    curr = 0;
    for (i = heightSize - 2; i >= idx; i--) {
        if (height[i] < height[temp]) {
            curr += (height[temp] - height[i]);
        } else {
            temp = i;
            rain += curr;
            curr = 0;
        }
    }
    return rain;
}