class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = int(nums.size());
        if(size == 0)
            return {-1, -1};
        int left(0), right(size - 1);
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else right = mid;
        }
        if(nums[left] == target)
        {
            for(int i = left + 1; i < size; i++)
            {
                if(nums[i] == target) right = i;
                else break;
            }
            return {left, right};
        }
        else return {-1, -1};
    }
};