class Solution {

public:
    int pathSum(TreeNode *root, int sum) {
        return root ? helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum) : 0;
    }

private:
    int helper(TreeNode *root, int sum) {
        return root ?
            (root->val == sum) +
            helper(root->left, sum - root->val) +
            helper(root->right, sum - root->val) :
            0;
    }
};