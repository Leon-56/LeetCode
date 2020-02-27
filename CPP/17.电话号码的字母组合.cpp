class Solution {
public:
    map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
                            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                            {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> res;
    string cur;
    vector<string> letterCombinations(string digits) {
        if(digits == "") return res;
        DFS(digits);
        return res;
    }
    void DFS(string digits)
    {
        if(!digits.size())
            res.push_back(cur);
        else
        {
            char num = digits[0];
            string letter = mp[num];
            int size = int(letter.size());
            for(int i = 0; i < size; i++)
            {
                cur.push_back(letter[i]);
                DFS(digits.substr(1));
                cur.pop_back();
            }
        }
    }
};