/**
 * There are n flights, and they are labeled from 1 to n.
 * 
 * We have a list of flight bookings.  The i-th booking bookings[i] = [i, j, k] means that we booked k seats from
 * flights labeled i to j inclusive.
 * 
 * Return an array answer of length n, representing the number of seats booked on each flight in order of their label.
 */

#include <stdlib.h>

int *corpFlightBookings(int **bookings, int bookingsSize, int *bookingsColSize, int n, int *returnSize) {
    *returnSize = n;
    int *ret = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; ++i) {
        ret[i] = 0;
    }
    for (int i = 0; i < bookingsSize; ++i) {
        int *curr = bookings[i];
        ret[curr[0] - 1] += curr[2];
        ret[curr[1]] -= curr[2];
    }
    for (int i = 1; i < n; ++i) {
        ret[i] += ret[i - 1];
    }
    return ret;
}