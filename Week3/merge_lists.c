/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* list3, * curr;

    if(!list1)
	{
		return list2;
	}
	else if (!list2)
	{
		return list1;
	}

	if (list1->val <= list2->val)
	{
		list3 = curr = list1;
		list1 = list1->next;
	}
	else
	{
		list3 = curr = list2;
		list2 = list2->next;
	}

	while(list1 && list2)
	{
		if (list1->val <= list2->val)
		{
			curr = curr->next = list1;
			list1 = list1->next;
		}
		else
		{
			curr = curr->next = list2;
			list2 = list2->next;
		}
	}

	if (list2)
	{
		curr->next = list2;
	}
	else
	{
		curr->next = list1;
	}

	return list3;

    }