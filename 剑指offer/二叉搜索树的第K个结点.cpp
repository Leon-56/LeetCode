/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k <= 0)
            return NULL;
        
        int count = 0;
        stack<TreeNode*> stack;
        TreeNode* node = pRoot;
        while(node != NULL || !stack.empty())
        {
            if(node != NULL)
            {
                stack.push(node);
                node = node -> left;
            }
            else
            {
                node = stack.top();
                stack.pop();
                count++;
                if(count == k)
                    return node;
                node = node -> right;
            }
        }
        return NULL;
    }
};