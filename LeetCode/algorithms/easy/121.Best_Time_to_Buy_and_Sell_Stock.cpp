class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> stack;
        for (auto& it : prices)
            stack.push(it);
        
        int max = -1, profit = -1;
        while (stack.empty() == false) {
            int val = stack.top();
            stack.pop();
            if (val > max)
                max = val;
            if (max - val > profit)
                profit = max - val;
        }
        return profit;
    }
};
