class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> res;
         int size = int(nums.size());
         if(size < 3) return res;
         sort(nums.begin(), nums.end());
         for(int k = 0; k < size - 2; k++)
         {
             if(nums[k] > 0) return res;
             if(k > 0 && nums[k] == nums[k - 1]) continue;
             int i(k + 1), j(size - 1);
             while(i < j)
             {
                 int sum = nums[k] + nums[i] + nums[j];
                 if(sum < 0)
                 {
                     // i+1，并且跳过重复的值
                     while(i < j && nums[i] == nums[++i]);
                 }
                 else if(sum > 0)
                 {
                     // j-1，并且跳过重复的值
                     while(i < j && nums[j] == nums[--j]);
                 }
                 else
                 {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[++i]);
                    while(i < j && nums[j] == nums[--j]);
                 }
             }
         }
         return res;
    }
};