class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) return 0;
        int ans = array[0];
        for(int i = 1; i < array.size(); i++)
        {
            if(array[i - 1] > 0) array[i] += array[i -1];
            if(ans < array[i]) ans = array[i];
        }
        return ans;
    }
};