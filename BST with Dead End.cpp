/*
 * GfG Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
 *
 * BST with Dead End
 *
 * Difficulty: Medium Accuracy: 35.99% Submissions: 85K+ Points: 4
 *
 * You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.
 * Your task is to determine whether the BST contains a dead end.
 * Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.
 *
 * Examples:
 * Input: root[] = [8, 5, 9, 2, 7, N, N, 1]
 * Output: true
 * Explanation: Node 1 is a Dead End in the given BST.
 *
 * Input: root[] = [8, 7, 10, 2, N, 9, 13]
 * Output: true
 * Explanation: Node 9 is a Dead End in the given BST.
 *
 * Constraints:
 * 1 <= number of nodes <= 3000
 * 1 <= node->data <= 10^5
 */

/************************************************************ C++ ************************************************/

class Solution {
public:
    // Helper DFS function to detect dead ends in BST
    bool dfs(Node* root, int min, int max) {
        if (!root) {
            return 0; // base case: empty subtree cannot have dead end
        }
        // if it's a leaf node
        if (!root->left && !root->right) {
            // check if no number can be inserted at or below this leaf
            if (root->data - min == 1 && max - root->data == 1) {
                return 1; // dead end found
            } else {
                return 0; // not a dead end
            }
        }
        // recursively check in left and right subtrees
        return dfs(root->left, min, root->data) ||
               dfs(root->right, root->data, max);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        return dfs(root, 0, INT_MAX);
    }
};
