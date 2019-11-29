class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode *tailA = headA;
        ListNode *tailB = headB;
        int stepA = 0;
        int stepB = 0;
        while (tailA->next) {
            tailA = tailA->next;
            ++stepA;
        }
        while (tailB->next) {
            tailB = tailB->next;
            ++stepB;
        }
        if (tailA != tailB) {
            return nullptr;
        }
        int delta = stepB - stepA;
        tailA = headA;
        tailB = headB;
        if (delta > 0) {
            while (delta > 0) {
                tailB = tailB->next;
                --delta;
            }
        } else {
            while (delta < 0) {
                tailA = tailA->next;
                ++delta;
            }
        }
        while (tailA != tailB) {
            tailA = tailA->next;
            tailB = tailB->next;
        }
        return tailA;
    }
};