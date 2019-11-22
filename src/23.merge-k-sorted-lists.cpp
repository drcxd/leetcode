/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (36.99%)
 * Total Accepted:    493.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        ListNode *head = lists[0];

        int i = 0;

        while (i < lists.size() - 1) {
            lists.push_back(mergeTwoLists(lists[i] , lists[i + 1]));
            i += 2;
        }

        return lists[lists.size() - 1];
    }

private:

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
