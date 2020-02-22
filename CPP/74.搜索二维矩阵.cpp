class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 特殊情况处理
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int row = int(matrix.size()), col = int(matrix[0].size());
        int begin(0), end(row * col - 1);
        while(begin < end)
        {
            int mid = begin + (end - begin) / 2;
            if(matrix[mid / col][mid % col] < target)
                begin = mid + 1;
            else end = mid;
        }
        return matrix[begin / col][begin % col] == target;
    }
};