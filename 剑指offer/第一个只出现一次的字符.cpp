class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str == "") return -1;
        int cnt[256];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < str.length(); i++)
        {
            cnt[str[i]]++;
        }
        for(int i = 0; i < str.length(); i++)
        {
            if(cnt[str[i]] == 1) return i;
        }
        return -1;
    }
};