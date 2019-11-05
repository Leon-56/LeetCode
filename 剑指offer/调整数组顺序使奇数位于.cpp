class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int left, right;
        left = 0;
        int temp;
        while(left < array.size())
        {
            while(left < array.size() && array[left] % 2 == 1)
                left++;
            right = left;
            while(right < array.size() && array[right] % 2 == 0)
                right++;
            if(right < array.size())
            {
                temp = array[right];
                while(right > left)
                {
                    array[right] = array[right - 1];
                    right--;
                }
                array[left] = temp;
            }
            else left = array.size();
        }
    }
};