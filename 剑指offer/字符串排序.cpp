/*全排序
* 方法一：递归法，先固定一个字符，求剩余字符的全排序
* 
*/
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if(str.empty()) return ans;
        Permutation(str, ans, 0);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    void Permutation(string str, vector<string>& ans, int begin)
    {
        if(begin == str.size() - 1)
        {
            if(find(ans.begin(), ans.end(), str) == ans.end())
                ans.push_back(str);
        }
        else
        {
            for(int i = begin; i < str.size(); i++)
            {
                swap(str[i], str[begin]);
                Permutation(str, ans, begin + 1);
                swap(str[i], str[begin]);
            }
        }
    }
    void swap(char& fir, char& sec)
    {
        char temp = fir;
        fir = sec;
        sec = temp;
    }
};

//方法二：字典序全排序列
