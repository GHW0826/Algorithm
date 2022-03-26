
// 1. 양쪽
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        string num = to_string(x);
        for (int i = 0; i < num.size() / 2; ++i)
            if (num[i] != num[num.size() - 1 - i])
                return false;
        return true;
    }
};

// 2. 그냥 쪼개서 뒤집고 비교
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        string num = to_string(x);     
        string sub1 = num.substr(0, num.size() / 2);
        string sub2 = 
            num.size() % 2 == 0 ? 
                num.substr(num.size() / 2, num.size()) :
                num.substr(num.size() / 2 + 1, num.size());
        
        reverse(sub2.begin(), sub2.end());
        if (sub1 != sub2)
            return false;
        
        return true;
    }
};
