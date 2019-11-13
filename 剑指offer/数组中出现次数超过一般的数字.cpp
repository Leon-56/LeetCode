class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) return 0;
        if(numbers.size() == 1) return numbers[0];
        sort(numbers.begin(), numbers.end());
        int count = 0;
        int temp = numbers[0];
        for(int i = 0; i < numbers.size(); i++)
        {
            if(count > numbers.size() / 2) return temp;
            if(numbers[i] == temp) count++;
            else
            {
                temp = numbers[i];
                count = 1;
            }
        }
        if(count > numbers.size() / 2) return temp;
        else return 0;
    }
};