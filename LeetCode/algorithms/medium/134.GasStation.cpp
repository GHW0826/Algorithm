class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas = 0;
        int sum_cost = 0;
        int curr_gas = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum_gas += gas[i];
            sum_cost += cost[i];

            curr_gas += gas[i] - cost[i];
            if (curr_gas < 0) {
                start = i + 1;
                curr_gas = 0;
            }
        }
        return (sum_gas < sum_cost) ? -1 : start;
    }
};
