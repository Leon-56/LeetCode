/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* fast = pHead;
        ListNode* low = pHead;
        while(fast && fast -> next)
        {
            low = low -> next;
            fast = fast -> next -> next;
            if(fast == low)
                break;
        }
        if(!fast || !fast -> next) return NULL;
        
        low = pHead;
        while(low != fast)
        {
            low = low -> next;
            fast = fast -> next;
        }
        return low;
    }
};