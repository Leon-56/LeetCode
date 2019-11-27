class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() == 0) return false;
        sort(numbers.begin(), numbers.end());
        int cnt = 0, tmp = 0;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(numbers[i] == 0) cnt++;
            else
            {
                if(tmp == 0) tmp = numbers[i];
                else
                {
                    if(numbers[i] == tmp + 1)
                        tmp++;
                    else if(numbers[i] == tmp) return false;
                    else
                    {
                        if(numbers[i] - tmp - 1 <= cnt)
                        {
                            cnt -= numbers[i] - tmp - 1;
                            tmp = numbers[i];
                        }
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};