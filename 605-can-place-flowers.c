/**
 * Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot
 * be planted in adjacent plots - they would compete for water and both would die.
 * 
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a
 * number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
 * 
 * Note:
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 */

#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int maxn = 0;
    int space = 1;
    for (int i = 0; i < flowerbedSize; ++i) {
        if (flowerbed[i]) {
            maxn += (space - 1) / 2;
            space = 0;
        } else
            ++space;
        if (maxn >= n) return true;
    }
    maxn += space / 2;
    return maxn >= n;
}