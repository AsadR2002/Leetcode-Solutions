class Solution {
    public:
        int maxArea(vector<int>& height) {
            int res = 0; 
    
            int l = 0, r = height.size() - 1; 
    
            while(l < r){
                int area = (r - l) * min(height[l], height[r]); 
    
                res = max(area, res); 
    
                if(height[r] < height[l]) {
                    r--;
                }
                else {
                    l++;
                }
            }
    
            return res;   
        }
};