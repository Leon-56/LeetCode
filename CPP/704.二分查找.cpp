class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = int(nums.size());
        if(size == 0) return -1;
        int left(0), right = size - 1, mid(0);
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else
            {
                if(nums[mid] == target)
                    return mid;
                right = mid;
            }
        }
        if(nums[left] == target)
            return left;
        else return -1;
    }
};