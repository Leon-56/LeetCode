class Solution {
public:
    long long cnt = 0;
    int InversePairs(vector<int> data)
    {
        int len = data.size();
        if(len <= 1) return 0;
        vector<int> copy;
        for(int i = 0; i < len; i++)
            copy.push_back(data[i]);
        mergSort(data, copy, 0, len - 1);
        return (int) (cnt % 1000000007);
    }
    void mergSort(vector<int>& data, vector<int>& copy, int low, int high)
    {
        if(high < low + 1) return;
        int mid = low + (high - low) / 2;
        mergSort(data, copy, low, mid);
        mergSort(data, copy, mid + 1, high);
        merg(data, copy, low, mid, high);
    }
    void merg(vector<int>& data, vector<int>& copy, int low, int mid, int high)
    {
        int i = low, j = mid + 1, k = low;
        while(i <= mid || j <= high)
        {
            if(i > mid)
                copy[k] = data[j++];
            else if(j > high)
                copy[k] = data[i++];
            else if(data[i] <= data[j])
                copy[k] = data[i++];
            else
            {
                copy[k] = data[j++];
                cnt += mid - i + 1;
            }
            k++;
        }
        for(int i = low; i <= high; i++)
            data[i] = copy[i];
    }
};