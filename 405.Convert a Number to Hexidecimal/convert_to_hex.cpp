class Solution {
    public:
        string toHex(int num) {
            if(num == 0) return to_string(0); 
            unsigned int n = num;
            string digits = "0123456789abcdef";
            string res = "";
            while(n > 0) {
                int rem = n% 16; 
                res+=digits[rem];
                n /= 16;
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };