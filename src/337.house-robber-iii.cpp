class Solution {
public:
    // int rob(TreeNode *root) {
    //     if (root == nullptr) {
    //         return 0;
    //     }
    //     if (dict.find(root) != dict.end()) {
    //         return dict[root];
    //     }
    //     int v1 = 0;
    //     v1 = root->val +
    //         (root->left ? rob(root->left->left) + rob(root->left->right) : 0) +
    //         (root->right ? rob(root->right->left) + rob(root->right->right) : 0);
    //     int v2 = 0;
    //     v2 = rob(root->left) + rob(root->right);
    //     dict[root] = max(v1, v2);
    //     return dict[root];

    // }
    int rob(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        int l = 0, r = 0;
        res = rob(root, l, r);
        return res;
    }
private:
    int rob(TreeNode *root, int &l, int &r) {
        if (root == nullptr) {
            return 0;
        }
        int ll, lr, rl, rr;
        ll = lr = rl = rr = 0;
        l = rob(root->left, ll, lr);
        r = rob(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
    // unordered_map<TreeNode *, int> dict;
};