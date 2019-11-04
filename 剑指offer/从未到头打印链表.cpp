/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        while(head != NULL)
        {
            ans.push_back(head->val);
            head = head -> next;
        }
        int temp;
        for(int i = 0; i < ans.size()/2; i++)
        {
            temp = ans[i];
            ans[i] = ans[ans.size() - i - 1];
            ans[ans.size() - i - 1] = temp;
        }
        return ans;
    }
};