class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int f = 0;
        int s = 1;
        int ans;
        for(int i = 2; i <= n; i++)
        {
            ans = f + s;
            f = s;
            s = ans;
        }
        return ans;
    }
};