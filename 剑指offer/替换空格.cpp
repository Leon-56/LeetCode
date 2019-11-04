class Solution {
public:
	void replaceSpace(char *str,int length) {
        string ans;
        for(int i = 0; i < length; i++)
        {
            if(str[i] == ' ')ans += "%20";
            else ans += str[i];
        }
        for(int i = 0; i < ans.size(); i++)
        {
            str[i] = ans[i];
        }
	}
};