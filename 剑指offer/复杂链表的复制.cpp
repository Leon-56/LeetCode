/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) 
    {
        if(!pHead) return NULL;
        RandomListNode* cur = pHead;
        while(cur)
        {
            RandomListNode* clone = new RandomListNode(cur -> label);
            clone -> next = cur -> next;
            cur -> next = clone;
            cur = clone -> next;
        }
        cur = pHead;
        while(cur)
        {
            if(cur -> random)
                cur -> next -> random = cur -> random -> next;
            cur = cur -> next -> next;
        }
        cur = pHead;
        RandomListNode* pCloneHead = pHead -> next;
        while(cur -> next)
        {
            RandomListNode* next = cur -> next;
            cur -> next = next -> next;
            cur = next;
        }
        return pCloneHead;
    }
};
