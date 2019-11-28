class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow, *entry;
        fast = slow = entry = head;
        while (fast && slow && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};