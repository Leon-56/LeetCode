class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = int(nums.size());
        if(size == 0)
            return -1;
        int left(0), right(size - 1);
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < nums[right])
            {
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else right = mid - 1;
            }
            else
            {
                if(nums[mid] > target && nums[left] <= target)
                    right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};