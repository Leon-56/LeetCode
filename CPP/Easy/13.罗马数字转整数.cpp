/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 * 注意长度为2的子串记录的值是（实际值 - 子串内左边罗马数字代表的数值）
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        // Import : IV = 3 IX = 8 XL = 30...
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, 
                                        {"X", 10}, {"XL", 30}, 
                                        {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, 
                                        {"CM", 800}, {"D", 500}, {"M", 1000}};
        int r = m[s.substr(0, 1)];
        for(int i = 1; i < s.size(); i++) {
            string two = s.substr(i - 1, 2);
            string one = s.substr(i, 1);
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
};
// @lc code=end

