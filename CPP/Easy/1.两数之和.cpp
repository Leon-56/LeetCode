/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans(2, -1);
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(target - nums[i]) > 0) {
                ans[0] = m[target - nums[i]];
                ans[1] = i;
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};
// @lc code=end

