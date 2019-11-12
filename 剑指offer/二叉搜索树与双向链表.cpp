/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* head = NULL;
    TreeNode*  pre = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        inOrder(pRootOfTree);
        return head;
    }
    void inOrder(TreeNode* node)
    {
        if(!node) return;
        inOrder(node -> left);
        node -> left = pre;
        if(pre) pre -> right = node;
        pre = node;
        if(!head) head = node;
        inOrder(node -> right);
    }
};