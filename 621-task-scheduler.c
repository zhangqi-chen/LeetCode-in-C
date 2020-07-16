/**
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters
 * represent different tasks. Tasks could be done without original order. Each task could be done in one interval.
 * For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n
 * intervals that CPU are doing different tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 */

int num[26] = {0};

int cmp(const void *a, const void *b) { return num[*(int *)b] - num[*(int *)a]; }

int leastInterval(char *tasks, int tasksSize, int n) {
    int ready[26] = {0};
    int most[26];
    for (int i = 0; i < tasksSize; ++i) {
        ++num[tasks[i] - 'A'];
    }
    for (int i = 0; i < 26; ++i) {
        most[i] = i;
    }
    qsort(most, 26, sizeof(int), cmp);
    int time = 0;
    int taskleft = tasksSize;
    while (taskleft > 0) {
        int chose = -1;
        for (int i = 0; i < 26; ++i) {
            if (ready[most[i]] > 0 || num[most[i]] == 0) continue;
            chose = most[i];
            --num[chose];
            --taskleft;
            ready[chose] = n + 1;
            break;
        }
        if (chose >= 0) qsort(most, 26, sizeof(int), cmp);
        for (int i = 0; i < 26; ++i) {
            if (ready[i] == 0) continue;
            --ready[i];
        }
        ++time;
    }
    return time;
}