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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ans;
        // 判空
        if(pRoot == NULL)
            return ans;
        queue<TreeNode*> que;
        que.push(pRoot);
        bool even = false;
        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++)
            {
                TreeNode* tmp = que.front();
                que.pop();
                vec.push_back(tmp -> val);
                // 压入子结点
                if(tmp -> left != NULL)
                    que.push(tmp -> left);
                if(tmp -> right != NULL)
                    que.push(tmp -> right);
            }
            // 偶数时翻转
            if(even)
                std::reverse(vec.begin(), vec.end());
            ans.push_back(vec);
            even = !even;
        }
        return ans;
    }
    
};