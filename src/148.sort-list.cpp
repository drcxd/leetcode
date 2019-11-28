class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        quickSortList(head, tail);
        return head;
    }

private:
    void quickSortList(ListNode *head, ListNode *tail) {
        if (!head || !tail) {
            return;
        }
        if (head == tail) {
            return;
        }
        ListNode *pivot = head;
        ListNode *smaller = head;
        ListNode *it = head->next;

        while (it != tail->next) {
            if (it->val < pivot->val) {
                smaller = smaller->next;
                swap(it->val, smaller->val);
            }
            it = it->next;
        }
        swap(pivot->val, smaller->val);
        quickSortList(head, smaller);
        quickSortList(smaller->next, tail);
    }
};