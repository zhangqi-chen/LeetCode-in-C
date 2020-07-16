/**
 * There are N children standing in a line. Each child is assigned a rating value.
 * 
 * You are giving candies to these children subjected to the following requirements:
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */

#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
    int cdy = 1;
    int curr = -1;
    int prev = INT_MAX;
    for (int i = 1; i < ratingsSize; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            if (curr > 0)
                cdy += (++curr);
            else {
                if (-curr >= prev) cdy += 1 - curr - prev;
                curr = 2;
                cdy += 2;
                prev = INT_MAX;
            }
        } else if (ratings[i] < ratings[i - 1]) {
            if (curr < 0)
                cdy -= (--curr);
            else {
                prev = curr;
                curr = -1;
                cdy += 1;
            }
        } else {
            if (-curr >= prev) cdy += 1 - curr - prev;
            curr = -1;
            cdy += 1;
            prev = INT_MAX;
        }
    }
    if (-curr >= prev) cdy += 1 - curr - prev;
    return cdy;
}