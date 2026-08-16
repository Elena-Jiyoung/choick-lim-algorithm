class MinStack {
private:
    std::stack<int> values;
    std::stack<int> mins;
public:
    MinStack() {
    }
    
    void push(int val) {
        values.push(val);
        if (mins.size() == 0) {
            int min = val;
            mins.push(val);
        }
        else {
            int min = std::min(val, mins.top());
            mins.push(min);
        }
        
    }
    
    void pop() {
        values.pop();
        mins.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
