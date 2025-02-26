class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end());
    
            int removed = 0; 
    
            if(intervals.size() <= 1) return 0;
    
            vector<int> prev = intervals[0];
    
            for(int i = 1; i < intervals.size(); i++) {
                int curr_start = intervals[i][0];
                int curr_end = intervals[i][1];
                
                int prev_start = prev[0];
                int prev_end = prev[1];
    
                if(curr_start >= prev_end) {
                    //no over lap
                    prev = intervals[i];
                }
                else {
                    removed++; 
                    if(prev[1] > intervals[i][1]) {
                        //remove prev
                        prev = intervals[i];
                    }
                    else {
                        // remove intervals[i]
                        continue;
                    }
                }
            }
            return removed;
        }
};