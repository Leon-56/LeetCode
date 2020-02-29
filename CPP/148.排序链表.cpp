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
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto ptr = head;
        int length = 0;
        while(ptr)
        {
            length++;
            ptr = ptr->next;
        }
        for(int size = 1; size < length; size *= 2)
        {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            while(cur)
            {
                auto left = cur;
                auto right = cut(cur, size);
                cur = cut(right, size);
                tail->next = merge(left, right);
                while(tail->next)
                    tail = tail->next;
            }
        }
        return dummyHead.next;
    }

    ListNode* cut(ListNode* head, int n)
    {
        auto ptr = head;
        while(ptr && --n)
            ptr = ptr->next;
        if(!ptr) return nullptr;
        auto next = ptr->next;
        ptr->next = nullptr;
        return next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummyHead(0);
        auto ptr = &dummyHead;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                ptr->next = l1;
                ptr = l1;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                ptr = l2;
                l2 = l2->next;
            }
        }
        ptr->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};