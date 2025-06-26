/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* mid = head;
    struct ListNode* end = head;

    while (end && end->next)
    {
        mid = mid->next;
        end = end->next->next;
    }

    return mid;
}