class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> temp;
        int count = 0;
        int head = 0;
        while(count < pushV.size())
        {
            temp.push(pushV[count]);
            while(!temp.empty() && temp.top() == popV[head])
            {
                temp.pop();
                head++;
            }
            count++;
        }
        if(temp.empty()) return true;
        else return false;
        
    }
};