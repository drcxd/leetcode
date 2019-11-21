/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (49.97%)
 * Total Accepted:    751K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode *i1 = l1, *i2 = l2;
        ListNode *i1p = nullptr, *i2p = nullptr;
        while (i1 && i2) {
            ListNode *temp;
            if (i1->val < i2->val) {
                if (i2p) {
                    i2p->next = i1;
                    i2p = i1;
                }
                temp = i1->next;
                i1->next = i2;
                i2p = i1;
                i1 = temp;
                i1p = nullptr;
            } else {
                if (i1p) {
                    i1p->next = i2;
                    i1p = i2;
                }
                temp = i2->next;
                i2->next = i1;
                i1p = i2;
                i2 = temp;
                i2p = nullptr;
            }
        }
        return l1->val < l2->val ? l1 : l2;
    }
};
