class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum(nums[0]), tmpSum(0);
        int size = int(nums.size());
        for(int i = 0; i < size; i++)
        {
            if(tmpSum >= 0)
                tmpSum += nums[i];
            else
            {
                tmpSum = nums[i];
            }
            maxSum = max(maxSum, tmpSum);
        }
        return maxSum;
    }
};