class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int cnt = 0;
        sort(data.begin(), data.end());
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i] == k) cnt++;
            else if(data[i] > k) return cnt;
        }
        return cnt;
    }
};