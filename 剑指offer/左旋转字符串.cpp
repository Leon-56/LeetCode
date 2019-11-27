class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        n = n % len;
        char ans[len];
        for(int i = 0; i < len; i++)
        {
            if(i - n >= 0) ans[i - n] = str[i];
            else ans[i - n + len] = str[i];
        }
        return ans;
    }
};