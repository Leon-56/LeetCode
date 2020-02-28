class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int size = int(nums.size());
        if(size == 0) return res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(true)
        {
            int left(size - 1);
            while(left > 0 && nums[left - 1] >= nums[left])
                left--;
            // 循环终止条件
            if(left == 0) return res;
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
            res.push_back(nums);
        }
    }
};