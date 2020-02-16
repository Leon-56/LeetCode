class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int left(1), right(x), mid(0);
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(mid < x / mid)
                left = mid + 1;
            else right = mid;
        }
        if(left > x / left)
            return left - 1;
        else return left;
    }
};