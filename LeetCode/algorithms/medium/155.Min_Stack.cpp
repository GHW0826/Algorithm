class MinStack {
public:
    vector<int> s;
    MinStack() {
    }
    
    void push(int val) {
        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s[s.size() -1];
    }
    
    int getMin() {
        return *min_element(s.begin(), s.end());
    }
};
