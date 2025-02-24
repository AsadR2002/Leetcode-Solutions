class Solution {
    public:
        int hammingWeight(int n) {
            int res = 0; 
            while(n) {
                if(n & (1)) res++; 
                n = n >> 1;
            }
            return res;
            
        }
};