class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ans;
        int start = 1, end = 2;
        int curSum = 3;
        while(end < sum)
        {
            if(curSum < sum)
            {
                end++;
                curSum += end;
            }
            else if(curSum > sum)
            {
                curSum -= start;
                start++;
            }
            else
            {
                vector<int> temp;
                for(int i = start; i <= end; i++)
                    temp.push_back(i);
                ans.push_back(temp);
                curSum -= start;
                start++;
                end++;
                curSum += end;
            }
        }
        return ans;
    }
};