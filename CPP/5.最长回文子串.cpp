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

// 中心拓展法
class Solution {
public:
    string longestPalindrome(string s) {
        int size = int(s.size());
        if(size == 0 || size == 1)
            return s;
        int start(0), end(0), maxLength(0);
        for(int i = 0; i < size; i++)
        {
            int length1 = expendAroundCenter(s, i, i);
            int length2 = expendAroundCenter(s, i, i + 1);
            maxLength = max({maxLength, length1, length2});
            if(maxLength > end - start + 1)
            {
                start = i - (maxLength - 1) / 2;
                end = i + maxLength / 2;
            }
        }
        return s.substr(start, maxLength);
    }
    int expendAroundCenter(string &s, int _left, int _right)
    {
        int left(_left), right(_right);
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};