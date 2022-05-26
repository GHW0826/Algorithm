155. Min Stack
  - cpp
```cpp
// 1.
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

// 2.
```

  - java
```java
  // 1.
  class MinStack {
    ArrayList<Integer> stack_ = new ArrayList<>();
    
    public MinStack() {}
    
    public void push(int val) {
        stack_.add(val);
    }
    
    public void pop() {
        stack_.remove(stack_.size() - 1);
    }
    
    public int top() {
        return stack_.get(stack_.size() - 1);
    }
    
    public int getMin() {
        return Collections.min(stack_);
    }
}

// 2.
```

622. Design Circular Queue

  - cpp
```cpp
class MyCircularQueue {    
public:
    vector<int> queue_;
    int size_;
    int head_;
    int tail_;
    int capa_;
    
    MyCircularQueue(int k) {
       queue_.resize(k);
       size_ = k;
       capa_ = 0;
       head_ = 0;
       tail_ = k-1; 
    }
    
    bool enQueue(int value) {
       if(isFull() == true)
           return false;
        
       tail_ = (tail_ + 1) % size_;
       queue_[tail_] = value;
       capa_++; 
       return true; 
    }
    
    bool deQueue() {
       if(isEmpty() == true)
           return false;
       head_ = (head_ + 1) % size_;
       capa_--;
       return true; 
    }
    
    int Front() {
        if(isEmpty() == true)
            return -1;
        return queue_[head_];
    }
    
    int Rear() {
        if(isEmpty()==true)
            return -1;
        return queue_[tail_]; 
    }
    
    bool isEmpty() {
        return (capa_ == 0);
    }
    
    bool isFull() {
        return (size_ == capa_);
    }
};
```


946. Validate Stack Sequences

  - cpp
```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int popped_index = 0;
        int pushed_index = 0;
        stack<int> container;
        
        while (pushed_index < pushed.size()) {
            container.push(pushed[pushed_index]);
            ++pushed_index;
            
            while (container.empty() == false && popped[popped_index] == container.top()) {
                container.pop();
                ++popped_index;
            }
        }
        return container.empty();
    }
};
```

  - java
```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int popped_index = 0;
        int pushed_index = 0;
        Stack<Integer> stack = new Stack<>();
        
        while (pushed_index < pushed.length) {
            stack.push(pushed[pushed_index]);
            ++pushed_index;
            
            while (stack.empty() == false && popped[popped_index] == stack.peek()) {
                stack.pop();
                ++popped_index;
            }
        }
        
        return stack.empty();
    }
}
```


304. Range Sum Query 2D - Immutable

  - cpp
```cpp
// 1. time limit
class NumMatrix {
public:
    vector<vector<int>> matrix_;
    NumMatrix(vector<vector<int>>& matrix) {
        matrix_ = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i)
            for (int j = col1; j <= col2; ++j)
                sum += matrix_[i][j];
        return sum;
    }
};

// 2.
class NumMatrix {
public:
    vector<vector<int>> matrix_;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            vector<int> row;
            int sum = 0;
            for (int j = 0; j < cols; ++j) {
                sum += matrix[i][j];
                row.push_back(sum);
            }
            matrix_.emplace_back(row);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            if (col1 >= 1)
                sum += matrix_[i][col2] - matrix_[i][col1 - 1];
            else
                sum += matrix_[i][col2];
        }

        return sum;
    }
};

// 3.
```


895. Maximum Frequency Stack

  - cpp
```cpp
// 1. time limit
class FreqStack {
public:
    map<int, int> table_;
    vector<int> st_;
    
    FreqStack() { }

    void push(int val) {
        ++table_[val];
        st_.push_back(val);
    }

    int pop() {
        int max = -1;
        int val = -1;
        int index = 0;
        if (st_.empty() == false) {
            for (int i = st_.size() - 1; i >= 0; --i) {
                if (max < table_[st_[i]]) {
                    index = i;
                    max = table_[st_[i]];
                    val = st_[i];
                }
            }

            st_.erase(st_.begin() + index);
            --table_[val];
        }

        return val;
    }
};

// 2.
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
```

1944. Number of Visible People in a Queue

  - cpp
```cpp
// 1. time limit
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> heights) {
        vector<int> answer(heights.size(), 0);
        for (int i = 0; i < heights.size(); ++i) {
            int sum = 0;
            int top = 0;
            for (int j = i + 1; j < heights.size(); ++j) {
                if (top < heights[j] && top < heights[i]) {
                    top = heights[j];
                    ++sum;
                }
            }
            answer[i] = sum;
        }
        return answer;
    }
};
```
