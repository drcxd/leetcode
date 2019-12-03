class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q) {
            return nullptr;
        }
        vector<TreeNode *> path1;
        vector<TreeNode *> path2;
        path1.push_back(root);
        path2.push_back(root);
        findNode(root, p, path1);
        findNode(root, q, path2);

        int i;
        for (i = 0; i < path1.size() && i < path2.size(); ++i) {
            if (path1[i] != path2[i]) {
                break;
            }
        }

        return path1[i - 1];
    }
private:
    bool findNode(TreeNode *root, TreeNode *n, vector<TreeNode *> &path) {
        if (root == nullptr) {
            return false;
        }
        if (root == n) {
            return true;
        }
        path.push_back(root->left);
        if (findNode(root->left, n, path)) {
            return true;
        }
        path.pop_back();
        path.push_back(root->right);
        if (findNode(root->right, n, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
};