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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(pHead != NULL)
        {
            pre = pHead;
            pHead = pHead -> next;
            pre -> next = next;
            next = pre;
        }
        return next;
    }
};