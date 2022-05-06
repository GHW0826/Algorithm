  - cpp
  
class MinStack {
public:
    // list<int> stack_;
    vector<int> stack_;
    
    MinStack() {}
    
    void push(int val) {
        stack_.push_back(val);
    }
    
    void pop() {
        stack_.pop_back();
    }
    
    int top() {
        return stack_.back();
    }
    
    int getMin() {
        return *min_element(stack_.begin(), stack_.end());
    }
};
