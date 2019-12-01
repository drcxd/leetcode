#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
}

class Solution {
public:
    // bool isPalindrome(ListNode *head) {
    //     vector<int> v;
    //     while (head) {
    //         v.push_back(head->val);
    //         head = head->next;
    //     }
    //     for (int i = 0, j = v.size() - 1; i <= j; ++i, --j) {
    //         if (v[i] != v[j]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    bool isPalindrome(ListNode *head) {
        if (head == nullptr) {
            return true;
        }

        int count = 0;
        int c = 0;
        ListNode *it = head;

        while (it) {
            ++count;
            it = it->next;
        }

        if (count == 1) {
            return true;
        }

        ListNode *mid = head;
        while (c != (count / 2) - 1) {
            mid = mid->next;
            ++c;
        }

        ListNode *next;
        if (count % 2 == 0) {
            next = mid->next;
        } else {
            next = mid->next->next;
        }

        mid->next = nullptr;

        // reverse head ... mid
        ListNode *r = reverse(head);

        // compare headd ... mid with next ... tail
        ListNode *it1 = r, *it2 = next;
        while (it1 && it2) {
            if (it1->val != it2->val) {
                return false;
            }
            it1 = it1->next;
            it2 = it2->next;
        }
        return true;

    }
private:

    ListNode *reverse(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode *it = head->next, *prev = head;
        ListNode *temp;
        while (it != nullptr) {
            temp = it->next;
            it->next = prev;
            prev = it;
            it = temp;
        }
        head->next = nullptr;
        return prev;
    }
};