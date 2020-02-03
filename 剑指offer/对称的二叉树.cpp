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
    bool isSymmetrical(TreeNode* pRoot)
    {
        // 判空
        if(pRoot == NULL)
            return true;
        return isSymmetrical(pRoot -> left, pRoot -> right);
    }
    // 画图
    bool isSymmetrical(TreeNode* left, TreeNode* right)
    {
        if(!left && !right)
            return true;
        if(!left || !right)
            return false;
        if(left -> val != right -> val)
            return false;
        return isSymmetrical(left -> left, right -> right) && 
            isSymmetrical(left -> right, right -> left);
    }

};