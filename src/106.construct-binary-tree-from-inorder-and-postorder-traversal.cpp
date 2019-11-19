/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (41.30%)
 * Total Accepted:    178.1K
 * Total Submissions: 425.4K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return subroutine(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
private:
    TreeNode *subroutine(vector<int> &inorder, int is, int ie,
                         vector<int> &postorder, int ps, int pe) {
        if (is >= ie || ps >= pe) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[pe - 1]);
        int lis, lie, lps, lpe;
        int ris, rie, rps, rpe;
        int count = 0;
        for (int i = is; i < ie; ++i) {
            if (inorder[i] == root->val) {
                lie = i;
                ris = i + 1;
                break;
            }
            ++count;
        }
        lis = is;
        lps = ps;
        lpe = lps + count;

        rie = ie;
        rpe = pe - 1;
        rps = lpe;

        root->left = subroutine(inorder, lis, lie, postorder, lps, lpe);
        root->right = subroutine(inorder, ris, rie, postorder, rps, rpe);
        return root;
    }
};
