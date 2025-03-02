class Solution {
    public:
        int myAtoi(string s) {
            int i = 0; 
            while(s[i] == ' ') i++;
    
            int sign = 1;
            if(s[i] == '+') i++; 
            else if(s[i] == '-') {
                sign = -1;
                i++;
            }
    
            while(s[i] == '0') i++;
    
            int32_t total = 0;
    
            while(isdigit(s[i])){
                int digit = s[i] - '0';
                if(total > (INT_MAX - digit) / 10) return sign == 1 ? INT_MAX : INT_MIN;
                total = total * 10 + digit;
                i++;
                
            }
    
            return total * sign;
            
        }
};