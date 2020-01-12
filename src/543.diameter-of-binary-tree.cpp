class Solution {

public:

    int diameterOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int d = 0;
        update(root, &d);
        return d;
    }

private:

    int update(TreeNode *root, int *d) {
        if (root == nullptr) {
            return 0;
        }
        int left = update(root->left, d);
        int right = update(root->right, d);
        if (left + right > *d) {
            *d = left + right;
        }
        return max(left, right) + 1;
    }

};