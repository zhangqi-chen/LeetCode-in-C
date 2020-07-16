/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 */

int numTrees(int n) {
    if (n < 2) return n;
    int tree[n + 1];
    tree[0] = 1;
    tree[1] = 1;
    for (int i = 2; i <= n; ++i) {
        tree[i] = 0;
        for (int j = 1; j <= (i + 1) / 2; ++j) {
            tree[i] += tree[j - 1] * tree[i - j] * 2;
            if (j - 1 == i - j) tree[i] -= tree[j - 1] * tree[i - j];
        }
    }
    return tree[n];
}