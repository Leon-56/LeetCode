/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "" ) return 0;
        if(haystack == "" ) return -1;
        bool finded = false;
        for(int i = 0; i < haystack.size(); i++) {
            for(int j = 0; j < needle.size(); j++) {
                if(haystack[i + j] != needle[j]) {
                    finded = false;
                    break;
                }
                else finded = true;
            }
            if(finded) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

