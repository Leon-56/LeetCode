class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0) return 1;
        if(base == 0) return 0;
        double ans = base;
        int i;
        for(i = 1; abs(exponent) >= pow(2, i); i++)
        {
            ans *= ans;
        }
        i = abs(exponent) - pow(2, i - 1);
        for(int j = 0; j < i; j++)
            ans *= base;
        if(exponent > 0)
            return ans;
        else return 1 / ans;
    }
};