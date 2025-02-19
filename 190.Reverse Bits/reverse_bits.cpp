class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t ans = 0;
            for(int i = 0; i < 32; i++) {
                int dig = (n & (1<<i)) >> i;
                ans |= dig << (31 - i);
            }
            return ans;
        }
    };