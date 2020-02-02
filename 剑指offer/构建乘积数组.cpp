class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> ans;
        int pre_sum = 1;
        int pos_sum = 1;
        int temp;
        for(int i = 0; i < A.size(); i++)
        {
            pos_sum = 1;
            
            for(int j = A.size() - 1; j > i; j--)
                pos_sum *= A[j];
            if(i == 0) temp = pos_sum;
            else temp = pre_sum * pos_sum;
            ans.push_back(temp);
            pre_sum *= A[i];
        }
        return ans;
    }
};