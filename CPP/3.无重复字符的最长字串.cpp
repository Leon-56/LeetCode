class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        unordered_map<char, int> hash;
        while(end < sSize)
        {
            char tmpChar = s[end];
            // 仅当[start, end)中包含s[end]时
            if(hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
            {
                start = hash[tmpChar] + 1;
                length = end - start;
            }
            hash[tmpChar] = end;

            length++;
            end++;
            result = max(result, length);
        }
        return result;
    }
};