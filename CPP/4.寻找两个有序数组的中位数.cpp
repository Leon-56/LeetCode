class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findKth(nums1, nums2, left) + findKth(nums1, nums2, right)) / 2.0; 
    }
    // 第k大的元素 => max(nums[i - 1], nums2[j - 1])
    // 其中:
    // i + j = k, nums1[i - 1] < nums2[j], nums2[j - 1] < nums1[i];
    int findKth(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        int left = max(0, k - n), right = min(k, m);
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums1[mid] < nums2[k - mid - 1])
                left = mid + 1;
            else right = mid;
        }
        int nums1Left = left == 0 ? INT_MIN : nums1[left - 1];
        int nums2Left = left == k ? INT_MIN : nums2[k - left - 1];
        return max(nums1Left, nums2Left);
    }
};