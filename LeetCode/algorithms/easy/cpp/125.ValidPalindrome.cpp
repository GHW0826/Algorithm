class Solution {
public:
    bool isPalindrome(string s) {
      
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) { 
            return !(std::isalpha(c) || std::isdigit(c)) ;
        }), s.end());
      
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c){ return tolower(c); });
      
        if (s.size() <= 0)
            return true;
        
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j)
            if (s[i] != s[j])
                return false;
        return true;
    }
};
