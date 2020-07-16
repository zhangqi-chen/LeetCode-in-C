/**
 * Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas. The guards have gone
 * and will come back in H hours.
 * 
 * Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K
 * bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more
 * bananas during this hour.
 * 
 * Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
 * 
 * Return the minimum integer K such that she can eat all the bananas within H hours.
 */

#include <stdlib.h>

int minEatingSpeed(int *piles, int pilesSize, int H) {
    int left = 1;
    int right = INT_MAX - 1;
    while (right > left) {
        int mid = (left + right) / 2;
        int time = 0;
        for (int i = 0; i < pilesSize; ++i) {
            time += (piles[i] + mid - 1) / mid;
            if (time > H) break;
        }
        if (time > H)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}