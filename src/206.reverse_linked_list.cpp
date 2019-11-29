class Solution {
public:
    // recursive
    // ListNode *reverseList(ListNode *head) {
    //     if (head == nullptr) {
    //         return nullptr;
    //     }
    //     if (head->next == nullptr) {
    //         return head;
    //     }
    //     ListNode *reverse = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return reverse;
    // }

    // iterative
    // ListNode *reverseList(ListNode *head) {
    //     if (head == nullptr) {
    //         return head;
    //     }
    //     stack<ListNode *> s;
    //     ListNode *it = head;
    //     while (it) {
    //         s.push(it);
    //         it = it->next;
    //     }
    //     ListNode *r = s.top();
    //     it = r;
    //     s.pop();
    //     while (!s.empty()) {
    //         ListNode *n = s.top();
    //         it->next = n;
    //         it = it->next;
    //         s.pop();
    //     }
    //     it->next = nullptr;
    //     return r;
    // }

    // iterative v2
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *p1 = head, *p2 = head->next;
        ListNode *temp;
        while (p2) {
            temp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = temp;
        }
        head->next = nullptr;
        return p1;
    }
};