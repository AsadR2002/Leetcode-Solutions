class Solution {
    public:
        int trap(vector<int>& height) {
            int trapped = 0; 
            int left_max = 0; 
            int right_max = 0; 
            vector<int> leftmaxes(height.size(), 0); 
            vector<int> rightmaxes(height.size(), 0);
    
            for(int i = 0; i < height.size(); i++) {
                leftmaxes[i] = left_max; 
                if(height[i] > left_max) left_max = height[i];
            }
    
            for(int i = height.size() - 1; i >= 0; i--) {
                rightmaxes[i] = right_max; 
                if(height[i] > right_max) right_max = height[i];
            }
    
    
            for(int i =0 ; i < height.size(); i++) {
                trapped += max(min(leftmaxes[i], rightmaxes[i]) - height[i], 0);
            }   
    
            return trapped;  
        }
};