class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(dividend == divisor) return 1;
            int sign = 1; 
    
            if(dividend < 0) sign*=-1; 
            if (divisor < 0 ) sign *= -1; 
    
            long n = abs((long)dividend); 
    
            long d = abs((long)divisor); 
            long q = 0;
    
            while(n >= d) {
                int cnt = 0; 
                while(n >= (d << (cnt + 1))) {
                    cnt++;
                }
    
                n -= d << cnt; 
                q += 1 << cnt;
            }
    
            if(q == 1<<31 && sign==1) return INT_MAX; 
            if(q == 1<<31 && sign==-1) return INT_MIN; 
    
    
            return sign * q; 
        }
    };