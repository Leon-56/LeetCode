/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        // 右子树非空，返回右子树最左下结点
        if(pNode -> right != NULL)
        {
            TreeLinkNode* node = pNode -> right;
            while(node -> left != NULL)
                node = node -> left;
            return node;
        }
        // 右子树为空，返还第一个父结点是左子树的结点
        else
        {
            while(pNode -> next != NULL)
            {
                TreeLinkNode* head = pNode -> next;
                if(head -> left == pNode)
                    return head;
                pNode = pNode -> next;
            }
            return NULL;
        }
    }
};