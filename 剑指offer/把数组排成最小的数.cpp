class Solution {
public:
    static bool cmp(string a, string b)
    {
        string s1 = a + b;
        string s2 = b + a;
        return s1 < s2;
    }
    string PrintMinNumber(vector<int> numbers) {
        vector<string> temp;
        string ans;
        for(int i = 0; i < numbers.size(); i++)
        {
            temp.push_back(std::to_string(numbers[i]));
        }
        sort(temp.begin(), temp.end(), cmp);
        for(int i = 0; i < temp.size(); i++)
            ans += temp[i];
        return ans;
    }
};