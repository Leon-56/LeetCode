class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(int(nums.size()) == 0)
            return 0;
        int left(0), mid(0), right = int(nums.size());
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else right = mid;
        }
        return left;
    }
};