/**
 * There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in
 * nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or indirect friends.
 * 
 * Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the
 * ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of
 * friend circles among all the students.
 */

void initUnion(int* parent, int size) {
    for (int i = 0; i < size; ++i) {
        parent[i] = i;
    }
}

int FindUnion(int* parent, int a) {
    if (parent[a] != a) {
        parent[a] = FindUnion(parent, parent[a]);
    }
    return parent[a];
}

void AddPair(int* parent, int a, int b) {
    int pa = FindUnion(parent, a);
    int pb = FindUnion(parent, b);
    if (pa < pb)
        parent[pb] = pa;
    else
        parent[pa] = pb;
}

int findCircleNum(int** M, int MSize, int* MColSize) {
    int* parent = (int*)malloc(sizeof(int) * MSize);
    initUnion(parent, MSize);
    for (int i = 0; i < MSize; ++i) {
        for (int j = 0; j < MSize; ++j) {
            if (M[i][j]) AddPair(parent, i, j);
        }
    }
    int* cnt = (int*)malloc(sizeof(int) * MSize);
    for (int i = 0; i < MSize; ++i) {
        cnt[i] = 0;
        FindUnion(parent, i);
    }
    for (int i = 0; i < MSize; ++i) {
        cnt[parent[i]] = 1;
    }
    int ret = 0;
    for (int i = 0; i < MSize; ++i) {
        if (cnt[i]) ++ret;
    }
    return ret;
}