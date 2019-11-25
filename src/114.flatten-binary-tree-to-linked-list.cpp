class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) {
            return;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->right = left;
        root->left = nullptr;

        if (left == nullptr) {
            root->right = right;
        } else {
            TreeNode *right_most_leaf = left;
            while (right_most_leaf->right != nullptr) {
                right_most_leaf = right_most_leaf->right;
            }
            right_most_leaf->right = right;
        }
        flatten(left);
        flatten(right);
    }
};