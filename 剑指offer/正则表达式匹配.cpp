class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        // 第二位不是 * ，直接进行判断
        if(*(pattern + 1) != '*')
        {
            if(*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str + 1, pattern + 1);
            else
                return false;
        }
        // 第二位是 * ，进行特殊判断
        else
        {
            if(*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str, pattern + 2) || match(str + 1, pattern);
            else
                return match(str, pattern + 2);
        }
    }
};