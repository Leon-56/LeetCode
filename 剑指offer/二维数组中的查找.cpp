class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        int n = array[1].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(array[i][0] > target) return false;
                if(array[i][j] == target) return true;
                if(array[i][j] > target) n = j;
            }
        return false;
    }
};