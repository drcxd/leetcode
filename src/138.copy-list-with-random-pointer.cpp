class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map <Node *, Node *> old2new;

        /**
         * Frist we copy the input list and build a map from the nodes
         * in the input list to nodes in the new list. Then we
         * traversal the new list using the map to find out which new
         * nodes corresponds to the original nodes stored in the
         * random field and substitute it.
         */
        Node *copy_head = new Node(head->val, head->next, head->random);
        old2new[head] = copy_head;

        Node *old_it = head->next;
        Node *copy_tail = copy_head;

        while (old_it) {
            Node *node = new Node(old_it->val, old_it->next, old_it->random);
            copy_tail->next = node;
            copy_tail = node;
            old2new[old_it] = copy_tail;
            old_it = old_it->next;
        }

        Node *copy_it = copy_head;
        while (copy_it) {
            if (copy_it->random) {
                copy_it->random = old2new[copy_it->random];
            }
            copy_it = copy_it->next;
        }
        return copy_head;
    }
};