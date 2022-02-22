class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool answer = false;
        while (n > 0) {
            if (n % 2 == 1) {
                if (answer == true)
                    return false;
                answer = true;   
            }
            n >>= 1;
        }
        
        return answer;
    }
};


// good
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) 
            return false;
        return ((n & (n-1)) == 0);
    }
};
