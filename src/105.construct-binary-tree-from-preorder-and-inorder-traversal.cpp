/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.50%)
 * Total Accepted:    273.9K
 * Total Submissions: 619.7K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = subroutine(preorder, 0, preorder.size(),
                                    inorder, 0, inorder.size());
        return root;
    }

private:
    TreeNode* subroutine(vector<int>& preorder, int ps, int pe,
                         vector<int>& inorder, int is, int ie) {
        if (ps >= pe || is >= ie) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[ps + 0]);
        int lps, lpe, lis, lie;
        int rps, rpe, ris, rie;
        int count = 0;
        for (int i = is; i < ie; ++i) {
            if (inorder[i] == root->val) {
                lie = i;
                ris = i + 1;
                break;
            }
            ++count;
        }
        lps = ps + 1;
        lpe = lps + count;
        lis = is;

        rps = lpe;
        rpe = pe;
        rie = ie;

        root->left = subroutine(preorder, lps, lpe, inorder, lis, lie);
        root->right = subroutine(preorder, rps, rpe, inorder, ris, rie);
        return root;
    }
};

// int main() {
//     return 0;
// }