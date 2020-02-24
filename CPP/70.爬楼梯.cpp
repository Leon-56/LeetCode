// 不能使用递归，会超时
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int first(1), second(2);
        for(int i = 3; i <= n; i++)
        {
            int tmp = first + second;
            first = second;
            second = tmp;
        }
        return second;
    }
};