class Solution {
public:
    int StrToInt(string str) {
        int len = str.size();
        if(len == 0) return 0;
        long long ans = 0;
        bool isNegative = (str[0] == '-');
        for(int i = 0; i < len; i++)
        {
            if(i == 0 && (str[i] == '+' || str[i] == '-'))
                continue;
            if(str[i] < '0' || str[i] > '9')
                return 0;
            ans = ans * 10 + (str[i] - '0');
        }
        if((!isNegative && ans > INT_MAX) || (isNegative && -1 * ans < INT_MIN)) return 0;
        return isNegative ? -ans : ans;
    }
};