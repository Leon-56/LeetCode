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

// O(n)解法双指针，从两侧向中间滑动
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = int(numbers.size());
        int low(0), high(size - 1);
        while(low < high)
        {
            int sum = numbers[low] + numbers[high];
            if(sum == target)
                return {low + 1, high + 1};
            else if(sum < target)
                low++;
            else high--;
        }
        return {-1, -1};
    }
};