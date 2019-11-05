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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k == 0) return NULL;
        ListNode* point1 = pListHead;
        ListNode* point2 = pListHead;
        int n = k - 1;
        while(n--)
        {
            if(point1 -> next == NULL) return NULL;
            point1 = point1 -> next;
        }
        while(point1 -> next != NULL)
        {
            point1 = point1 -> next;
            point2 = point2 -> next;
        }
        return point2;
    }
};