/**
 * Given n processes, each process has a unique PID (process id) and its PPID (parent process id).
 * 
 * Each process only has one parent process, but may have one or more children processes. This is just like a tree
 * structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will
 * be distinct positive integers.
 * 
 * We use two list of integers to represent a list of processes, where the first list contains PID for each process
 * and the second list contains the corresponding PPID.
 * 
 * Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes
 * that will be killed in the end. You should assume that when a process is killed, all its children processes will
 * be killed. No order is required for the final answer.
 */

#define PNUM 60000

typedef struct _process {
    int pid;
    struct _process *next;
} process;

int *killProcess(int *pid, int pidSize, int *ppid, int ppidSize, int kill, int *returnSize) {
    process *proc[PNUM] = {NULL};
    for (int i = 0; i < pidSize; ++i) {
        int parent = ppid[i];
        int child = pid[i];
        process *newp = (process *)malloc(sizeof(process));
        newp->pid = child;
        newp->next = proc[parent];
        proc[parent] = newp;
    }
    int *ret = (int *)malloc(sizeof(int) * PNUM);
    *returnSize = 1;
    ret[0] = kill;
    int start = 0;
    while (start < *returnSize) {
        int endSize = *returnSize;
        for (int i = start; i < endSize; ++i) {
            int parent = ret[i];
            process *curr = proc[parent];
            while (curr) {
                ret[(*returnSize)++] = curr->pid;
                curr = curr->next;
            }
        }
        start = endSize;
    }
    return ret;
}