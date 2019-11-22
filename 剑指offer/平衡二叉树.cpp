class Solution {
public:
    bool ans = true;
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        Depth(pRoot);
        return ans;
    }
    int Depth(TreeNode* pRoot)
    {
        if(!pRoot || !ans) return 0;
        int left = Depth(pRoot -> left);
        int right = Depth(pRoot -> right);
        if(abs(left - right) > 1) ans = false;
        return 1 + max(left, right);
    }
};