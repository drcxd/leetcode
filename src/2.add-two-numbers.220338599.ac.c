 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     struct ListNode *next;
  * };
  */
 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
     struct ListNode *head = NULL;
    struct ListNode **pointer = &head;
    char add_one = 0;
    while (l1 || l2 || add_one)
    {
        if (*pointer)
        {
            (*pointer)->next = malloc(sizeof(struct ListNode));
            pointer = &((*pointer)->next);
        }
        else
        {
            *pointer = malloc(sizeof(struct ListNode));
        }

        (*pointer)->val = 0;
        (*pointer)->next = NULL;
        if (l1)
        {
            (*pointer)->val += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            (*pointer)->val += l2->val;
            l2 = l2->next;
       }
        if (add_one)
        {
            ++(*pointer)->val;
            add_one = 0;
        }
        if ((*pointer)->val >= 10)
        {
            (*pointer)->val -= 10;
            add_one = 1;
        }
    }
     // if (add_one)
     // {
     //     (*pointer)->next = malloc(sizeof(struct ListNode));
     //     pointer = &((*pointer)->next);
     //     (*pointer)->val = 
     // }
    return head;
}

