class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode *> level;
        vector<vector<int>> res;

        if (!root) {
            return res;
        }

        level.push_back(root);

        helper(level, res, true);

        return res;
    }
private:

    void helper(vector<TreeNode *> &level, vector<vector<int>> &res, bool leftToRight) {
        if (level.empty()) {
            return;
        }

        vector<TreeNode *> copy = level;
        level.clear();

        vector<int> row;

        if (leftToRight) {
            for (int i = 0; i < copy.size(); ++i) {
                if (copy[i]) {
                    row.push_back(copy[i]->val);
                }
            }
        } else {
            for (int i = copy.size() - 1; i >= 0; --i) {
                if (copy[i]) {
                    row.push_back(copy[i]->val);
                }
            }
        }

        for (int i = 0; i < copy.size(); ++i) {
            if (copy[i]) {
                level.push_back(copy[i]->left);
                level.push_back(copy[i]->right);
            }
        }


        if (!row.empty()) {
            res.push_back(row);
        }
        helper(level, res, !leftToRight);
    }
};