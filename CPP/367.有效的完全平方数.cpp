class Solution {
public:
    bool isPerfectSquare(int num) {
        int left(1), right;
        // 注意int范围
        right = min(num, 46340);
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(num / mid > mid)
                left = mid + 1;
            else right = mid;
        }
        if(num == left * left)
            return true;
        else return false;
    }
};