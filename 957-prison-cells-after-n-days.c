/**
 * There are 8 prison cells in a row, and each cell is either occupied or vacant.
 * 
 * Each day, whether the cell is occupied or vacant changes according to the following rules:
 * 
 * If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
 * Otherwise, it becomes vacant.
 * (Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)
 * 
 * We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else
 * cells[i] == 0.
 * 
 * Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)
 */

int nextday(int cell) {
    return (~(cell ^ cell >> 2) & 63) << 1;
}

int *prisonAfterNDays(int *cells, int cellsSize, int N, int *returnSize) {
    int history[257];
    history[0] = 0;
    for (int i = 0; i < 8; ++i) {
        history[0] |= cells[i] << i;
    }
    int new, same = -1;
    for (new = 1; new < 257; ++new) {
        history[new] = nextday(history[new - 1]);
        for (int i = 1; i < new; ++i) {
            if (history[i] == history[new]) {
                same = i;
                break;
            }
        }
        if (same > 0 || new == N) break;
    }
    int ans = new == N ? history[N] : history[(N - same) % (new - same) + same];
    int *ret = (int *)malloc(sizeof(int) * 8);
    *returnSize = 8;
    for (int i = 0; i < 8; ++i) {
        ret[i] = ans >> i & 1;
    }
    return ret;
}