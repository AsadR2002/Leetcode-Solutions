class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            std::sort(intervals.begin(), intervals.end(), 
            [](const std::vector<int>& a, const std::vector<int>& b) {
                return a[0] < b[0];  // Sort in ascending order
            });
    
            vector<vector<int>> output; 
            output.push_back(intervals[0]); 
    
            for(int i = 1; i < intervals.size(); i++) {
                int start = intervals[i][0];
                int end = intervals[i][1];
    
                int last_added = output.back()[1]; 
    
                if(start <= last_added) {
                    output.back()[1] = max(end, last_added);
                }
                else output.push_back(intervals[i]);
    
            } 
    
            return output;
        }
};