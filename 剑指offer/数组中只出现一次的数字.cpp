class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        sort(data.begin(), data.end());
        *num1 = *num2 = 0;
        bool flag = true;
        for(int i = 1; i < data.size() - 1; i ++)
        {
            if(data[i] != data[i - 1] && data[i] != data[i + 1])
            {
                if(flag)
                {
                    flag = false;
                    *num1 = data[i];
                }
                else *num2 = data[i];
            }
        }
        if(data[data.size() - 1] != data[data.size() - 2]) *num2 = data[data.size() - 1];
    }
};