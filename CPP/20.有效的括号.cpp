/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        map<char, char> m = {{'}', '{'}, {')', '('}, {']', '['}};
        stack<char> res;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') res.push(s[i]);
            else {
                if(!res.empty() && res.top() == m[s[i]]) res.pop();
                else return false;
            }
        }
        if(res.empty()) return true;
        else return false;
    }
};
// @lc code=end

