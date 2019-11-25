class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > r;
        queue<TreeNode *> q1, q2;
        queue<TreeNode *> *p1 = &q1, *p2 = &q2;
        if (!root) {
            return r;
        }
        p1->push(root);
        do {
            vector<int> v;
            while (!p1->empty()) {
                TreeNode *n = p1->front();
                p1->pop();
                v.push_back(n->val);
                if (n->left != nullptr) {
                    p2->push(n->left);
                }
                if (n->right != nullptr) {
                    p2->push(n->right);
                }
            }
            r.push_back(v);
            swap(p1, p2);
        } while (!p1->empty());
        return r;
    }
};