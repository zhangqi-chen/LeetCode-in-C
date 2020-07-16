/**
 * Two players play a turn based game on a binary tree.  We are given the root of this binary tree, and the number of
 * nodes n in the tree.  n is odd, and each node has a distinct value from 1 to n.
 * 
 * Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n
 * and y != x.  The first player colors the node with value x red, and the second player colors the node with value y
 * blue.
 * 
 * Then, the players take turns starting with the first player.  In each turn, that player chooses a node of their
 * color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left
 * child, right child, or parent of the chosen node.)
 * 
 * If (and only if) a player cannot choose such a node in this way, they must pass their turn.  If both players pass
 * their turn, the game ends, and the winner is the player that colored more nodes.
 * 
 * You are the second player.  If it is possible to choose such a y to ensure you win the game, return true.  If it
 * is not possible, return false.
 * 
 * Constraints:
 * root is the root of a binary tree with n nodes and distinct node values from 1 to n.
 * n is odd.
 * 1 <= x <= n <= 100
 */

#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void searchChild(struct TreeNode* root, int** data) {
    if (!root) return;
    if (!root->left) {
        data[root->val][0] = 0;
    } else {
        searchChild(root->left, data);
        data[root->val][0] = data[root->left->val][0] + data[root->left->val][1] + 1;
    }
    if (!root->right) {
        data[root->val][1] = 0;
    } else {
        searchChild(root->right, data);
        data[root->val][1] = data[root->right->val][0] + data[root->right->val][1] + 1;
    }
}

void searchParent(struct TreeNode* root, int** data, int fromParent) {
    data[root->val][2] = fromParent;
    if (root->left) searchParent(root->left, data, fromParent + 1 + data[root->val][1]);
    if (root->right) searchParent(root->right, data, fromParent + 1 + data[root->val][0]);
}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x) {
    int** data = (int**)malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i <= n; ++i) {
        data[i] = (int*)malloc(sizeof(int) * 3);
    }
    searchChild(root, data);
    searchParent(root, data, 0);
    int left = data[x][0];
    int right = data[x][1];
    int parent = data[x][2];
    if (left > right + parent + 1) return true;
    if (right > left + parent + 1) return true;
    if (parent > left + right + 1) return true;
    return false;
}