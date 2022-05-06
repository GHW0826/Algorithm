  - cpp
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
