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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* head = new ListNode(0);
        head -> next = pHead;
        ListNode* pre = head;
        ListNode* last = head -> next;
        while(last)
        {
            if(last -> next != NULL && last -> val == last -> next -> val)
            {
                ListNode* tmp = pHead;
                while(last -> next != NULL && last -> val == last -> next -> val)
                {
                    last = last -> next;
                }
                pre -> next = last -> next;
                last = last -> next;
            }
            else
            {
                last = last -> next;
                pre = pre -> next;
            }
        }
        return head -> next;
    }
};