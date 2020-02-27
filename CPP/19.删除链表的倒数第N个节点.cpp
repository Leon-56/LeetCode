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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pHead = head;
        ListNode* pre = head;
        // 快指针先遍历n个结点
        while(n--)
            pre = pre -> next;
        // 已经走到结尾
        if(pre == NULL)
        {
            head = head -> next;
            return head;
        }
        // 快慢指针同时遍历
        while(pre -> next != NULL)
        {
            pHead = pHead -> next;
            pre = pre -> next;
        }
        pHead -> next = pHead -> next -> next;
        return head;
    }
};