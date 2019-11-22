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
    int ans = 0;
    int TreeDepth(TreeNode* pRoot)
    {
        Depth(pRoot, 0);
        return ans;
    }
    void Depth(TreeNode* pRoot, int num)
    {
        if(pRoot) 
        {
            num++;
            if(ans < num) ans = num;
            Depth(pRoot -> left, num);
            Depth(pRoot -> right, num);
        }
        else return;
    }
};