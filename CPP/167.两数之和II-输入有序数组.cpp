class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = int(numbers.size());
        map<int, int> m_map;
        vector<int> res;
        for(int i = 0; i < size; i++)
        {
            if(m_map.count(target - numbers[i]))
            {
                res.push_back(m_map[target - numbers[i]] + 1);
                res.push_back(i + 1);
                break;
            }
            m_map[numbers[i]] = i; 
        }
        return res;
    }
};