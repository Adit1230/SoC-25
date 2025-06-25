class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
       	ListNode* list3, curr;

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
			curr->next = list1;
			curr = list1;
			list1 = list1->next;
		}
		else
		{
			curr->next = list2;
			curr = list2;
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
};
