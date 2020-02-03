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
            vector<vector<int>> res;
            if(pRoot == NULL)
                return res;
            queue<TreeNode*> que;
            que.push(pRoot);
            while(!que.empty())
            {
                vector<int> vec;
                int size = que.size();
                for(int i = 0; i < size; i++)
                {
                    TreeNode* node = que.front();
                    que.pop();
                    vec.push_back(node -> val);
                    if(node -> left != NULL)
                        que.push(node -> left);
                    if(node -> right != NULL)
                        que.push(node -> right);
                }
                res.push_back(vec);
            }
            return res;
        }
    
};