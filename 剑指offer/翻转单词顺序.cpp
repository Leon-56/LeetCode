class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.size();
        int left = 0, right = len - 1;
        Reverse(str, left, right);
        for(int i = 0; i < len; i++)
        {
            if(str[i] == ' ')
            {
                right = i - 1;
                Reverse(str, left, right);
                left = i + 1;
            }
            else if(i == len - 1)
            {
                right = len - 1;
                Reverse(str, left, right);
            }
        }
        return str;
    }
    void Reverse(string& str, int left, int right)
    {
        while(left < right)
        {
            swap(str[right--], str[left++]);
        }
    }
};