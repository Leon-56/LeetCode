/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return NULL;
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        // 判断是否有环
        while(fast_ptr != NULL && fast_ptr -> next != NULL)
        {
            fast_ptr = fast_ptr -> next -> next;
            slow_ptr = slow_ptr -> next;
            // 快慢指针相遇
            if(fast_ptr == slow_ptr)
            {
                fast_ptr = head;
                while(fast_ptr != slow_ptr)
                {
                    fast_ptr = fast_ptr -> next;
                    slow_ptr = slow_ptr -> next;
                }
                return slow_ptr;
            }
        }
        return NULL;
    }
};