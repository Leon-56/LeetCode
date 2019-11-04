/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return BinaryTree(0, vin.size() - 1, 0, pre, vin);
    }
    
    TreeNode* BinaryTree(int preL, int preR, int inL, vector<int> pre, vector<int> vin) {
        if(preL <= preR)
        {
            for(int i = inL; i < vin.size(); i++)
            {
                if(vin[i] == pre[preL])
                {
                    TreeNode* T = new TreeNode(pre[preL]);
                    T->left = BinaryTree(preL + 1, preL + i - inL, inL, pre, vin);
                    T->right = BinaryTree(preL + i - inL + 1, preR, i + 1, pre, vin);
                    return T;
                }
            }
        }
        return NULL; 
    }
};
