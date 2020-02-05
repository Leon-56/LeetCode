class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;
        // 窗口大小为0
        if(size <= 0)
            return res;
        for(int i = 0; i < num.size(); i++)
        {
            // 清除队列后边所有比num[i]小的下标
            while(s.size() && num[s.back()] <= num[i])
                s.pop_back();
            // 下标区间超过窗口size，清除队首
            while(s.size() && i - s.front() + 1 > size)
                s.pop_front();
            // 压入下标
            s.push_back(i);
            // 长度大于窗口时开始压入
            if(i + 1 >= size)
                res.push_back(num[s.front()]);
        }
        return res;
    }
};