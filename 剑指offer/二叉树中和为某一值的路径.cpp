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
    vector<vector<int>> ans;
    vector<int> temp;
    void find(TreeNode* root, int sum)
    {
        temp.push_back(root -> val);
        if(!root -> left && !root -> right && root -> val == sum)
            ans.push_back(temp);
        else
        {
            if(root -> left) find(root -> left, sum - root -> val);
            if(root -> right) find(root -> right, sum - root -> val);
        }
        temp.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber)
    {
        if(root == NULL) return ans;
        find(root, expectNumber);
        return ans;
    }
};