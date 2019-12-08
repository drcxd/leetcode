class Solution {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!t) {
            return true;
        }
        if (!s) {
            return false;
        }
        if (isTreeEqual(s, t)) {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

private:

    bool isTreeEqual(TreeNode *lhs, TreeNode *rhs) {
        if (!lhs && !rhs) {
            return true;
        }
        if (!lhs || !rhs) {
            return false;
        }
        if (lhs->val != rhs->val) {
            return false;
        }
        return isTreeEqual(lhs->left, rhs->left) &&
            isTreeEqual(lhs->right, rhs->right);
    }
};