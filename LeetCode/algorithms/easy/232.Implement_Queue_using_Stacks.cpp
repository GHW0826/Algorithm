class MyQueue {
public:
    queue<int> q;
    
    MyQueue() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int peek() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
