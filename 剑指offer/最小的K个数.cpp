class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ans;
        if(k > input.size() || k <= 0) return ans;
        find(input, k - 1);
        for(int i = 0; i < k; i++)
            ans.push_back(input[i]);
        return ans;
    }
    void find(vector<int>& input, int k)
    {
        int low = 0;
        int high = input.size() - 1;
        while(low < high)
        {
            int j = Partitation(input, low, high);
            if(j == k) break;
            if(j < k) low = j + 1;
            else high = j - 1;
        }
    }
    int Partitation(vector<int>& input, int low, int high)
    {
        int p = input[low];
        int i = low + 1;
        int j = high;
        while(true)
        {
            while(i < j && input[i] < p) i++;
            while(i < j && input[j] > p) j--;
            if(i >= j) break;
            swap(input, i, j);
        }
        swap(input, low, j - 1);
        return j;
    }
    void swap(vector<int>& input, int l, int h)
    {
        int temp = input[l];
        input[l] = input[h];
        input[h] = temp;
    }
};