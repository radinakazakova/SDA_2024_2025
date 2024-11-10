//моето първо решение 2*n памет
class MinStack {
public:
    deque<int> minimums; //низходящ ред
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        minStack.push(val);
        if(minimums.empty())
        {
            minimums.push_back(val);
            return;
        }
        
        if(val > minimums.back())
            return;

        minimums.push_back(val);
    }
    
    void pop() {
        if(minStack.top() == minimums.back())
        {
            minimums.pop_back();
            minStack.pop();
        }
        else
        {
            minStack.pop();
        }
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return minimums.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
