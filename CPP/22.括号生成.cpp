class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS(res, "", 0, 0, n);
        return res;
    }
    void DFS(vector<string>& res, string str, int left, int right, int n)
    {
        if(left > n || right > n || right > left) return;
        if(left == n && right == n)
        {
            res.push_back(str);
            return;
        }
        DFS(res, str + '(', left + 1, right, n);
        DFS(res, str + ')', left, right + 1, n);
    }
};