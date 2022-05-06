  - cpp
  
class FreqStack {
public:
    map<int, int> table_;
    int index_ = 0;
    priority_queue<tuple<int, int, int>> q_;

    FreqStack() { }

    void push(int val) {
        int fre = ++table_[val];
        q_.emplace(make_tuple(fre, index_, val));
        ++index_;
    }

    int pop() {
        int val = 0;
        if (q_.empty() == false) {
            auto elem = q_.top();
            q_.pop();
            val = get<2>(elem);
            --table_[val];
        }

        return val;
    }
};
