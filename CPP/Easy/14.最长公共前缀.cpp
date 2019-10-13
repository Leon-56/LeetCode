/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];

        int pre_len = 0;
        while(pre_len < strs[0].length() &&
              pre_len < strs[1].length() &&
              strs[0][pre_len] == strs[1][pre_len])
        {
            pre_len++;
        }

        for(int i = 2; pre_len && i < strs.size(); i++)
        {
            if(strs[i].length() < pre_len)
                pre_len = strs[i].length();
            
            while(pre_len && strs[i][pre_len - 1] != strs[0][pre_len - 1])
                pre_len--;
        }
        return string(strs[0].begin(), strs[0].begin() + pre_len);
    }
};
// @lc code=end

