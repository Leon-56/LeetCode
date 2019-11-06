/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode* merge = NULL;
        ListNode* temp = NULL;
        while(pHead1 != NULL && pHead2 != NULL)
        {
            if(pHead1 -> val <= pHead2 -> val)
            {
                if(merge == NULL) 
                {
                    merge = temp = pHead1;
                }
                else 
                {
                    temp -> next = pHead1;
                    temp = temp -> next;
                }
                pHead1 = pHead1 -> next;
            }
            else
            {
                if(merge == NULL)
                {
                    merge = temp = pHead2;
                }
                else
                {
                    temp -> next = pHead2;
                    temp = temp -> next;
                }
                pHead2 = pHead2 -> next;
            }
        }
        if(pHead1 == NULL) temp -> next = pHead2;
        else temp -> next = pHead1;
        return merge;
        
    }
};