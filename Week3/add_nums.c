/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    char carry = 0, sum;
    struct ListNode* curr = l1;

    while(curr)
    {
        sum = curr->val + carry;

        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        
        if (sum > 9)
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;
        }

        curr->val = sum;

        if (curr->next)
        {
            curr = curr->next;
        }
        else if (l2)
        {
            curr = curr->next = l2;
            l2 = 0;
        }
        else
        {
            if (carry)
            {
                struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
                new_node->val = 1;
                curr->next = new_node;
                new_node->next = 0;
            }
            curr = 0;
        }

    }

    return l1;    
}