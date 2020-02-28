class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = int(nums.size());
        int left(size - 1);
        while(left > 0 && nums[left - 1] >= nums[left])
            left--;
        if(left == 0)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        int ptr = size - 1;
        while(ptr > 0 && nums[ptr] <= nums[left - 1])
            ptr--;
        swap(nums[ptr], nums[left - 1]);
        int right = size - 1;
        while(left < right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
};