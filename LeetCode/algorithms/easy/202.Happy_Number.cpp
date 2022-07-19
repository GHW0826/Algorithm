class Solution {
public:
    bool isHappy(int n) {
        set<long long> table;
        while (n != 1 && table.find(n) == table.end()) {
            int comp = n;
            table.insert(n);
            n = 0;
            while (comp > 0) {
                n += pow(comp % 10, 2);
                comp /= 10;
            }
        }

        return (n == 1) ? true : false;
    }
};
