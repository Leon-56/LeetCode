class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) return false;
        return Verify(sequence, 0, sequence.size() - 1);
    }
    bool Verify(vector<int> s, int low, int high)
    {
        if(low >= high) return true;
        int temp = s[high];
        int count = 0;
        while(temp > s[low + count]) count++;
        for(int i = low + count; i < high; i++)
            if(s[i] < temp) return false;
        return Verify(s, low, low + count - 1) &&
            Verify(s, low + count, high - 1);
    }
};