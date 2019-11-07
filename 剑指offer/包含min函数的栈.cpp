class Solution {
public:
    stack<int> stack1;
    stack<int> stack2;
    void push(int value) {
        if(stack2.empty()) stack2.push(value);
        else if(value < stack2.top()) stack2.push(value);
        stack1.push(value);
    }
    void pop() {
        if(!stack1.empty()); 
        {
            if(stack1.top() == stack2.top()) stack2.pop();
            stack1.pop();
        }
    }
    int top() {
        if(!stack1.empty())
            return stack1.top();
    }
    int min() {
        if(stack1.empty()) return NULL;
        return stack2.top();
    }
};