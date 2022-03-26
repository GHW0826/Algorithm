class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        for (int i = 0; i < 32; ++i)
            answer |= (1 & n >> i) << 31 - i;
        return answer;
    }
};
