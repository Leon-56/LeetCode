class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = int(height.size());
        int left(0), right(size - 1), maxArea(0);
        while(left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            maxArea = max(area, maxArea);
            if(height[left] < height[right])
                left++;
            else right--;
        }
        return maxArea;
    }
};