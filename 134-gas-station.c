/**
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * 
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
 * You begin the journey with an empty tank at one of the gas stations.
 * 
 * Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise
 * return -1.
 * 
 * Note:
 * If there exists a solution, it is guaranteed to be unique.
 * Both input arrays are non-empty and have the same length.
 * Each element in the input arrays is a non-negative integer.
 */

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int sum = 0;
    int curr = 0;
    int start = -1;
    for (int i = 0; i < gasSize;++i){
        int new = gas[i] - cost[i];
        sum += new;
        if (curr+new<0){
            curr = 0;
            start = -1;
        }else{
            if (start == -1) start = i;
            curr += new;
        }
    }
    if (sum < 0) return -1;
    return start;
}