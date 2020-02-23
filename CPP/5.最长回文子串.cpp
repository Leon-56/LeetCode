class Solution {
public:
    string longestPalindrome(string s) {
        int size = int(s.size());
        if(size == 0 || size == 1)
            return s;
        vector<vector<int>> dp(size, vector<int>(size));
        int start(0), max(1);
        // 初始化状态
        for(int i = 0; i < size; i++)
        {
            dp[i][i] = 1;
            if(i < size - 1 && s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start = i;
                max = 2;
            }
        }
        // 状态传递
        for(int i = 3; i <= size; i++)
        {
            for(int j = 0; i + j - 1 < size; j++)
            {
                if(s[j] == s[i + j - 1] && dp[j + 1][i + j - 2] == 1)
                {
                    dp[j][i + j - 1] = 1;
                    start = j;
                    max = i;
                }
            }
        }
        return s.substr(start, max);
    }
};