class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ans;
        int bot = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        if(bot + 1 == 0 || right + 1 == 0) return ans; 
        int top = 0;
        int left = 0;
        int i;
        while(left <= right && top <= bot)
        {
            for(i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            for(i = top + 1; i <= bot; i++)
                ans.push_back(matrix[i][right]);
            for(i = right - 1; bot > top && i >= left; i--)
                ans.push_back(matrix[bot][i]);
            for(i = bot - 1; left < right && i > top; i--)
                ans.push_back(matrix[i][left]);
            right--;left++;bot--;top++;
        }
        return ans;
    }
};