class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> res;
            bool added = false;
    
            for(auto& cur_range : intervals) {
                    if(cur_range[0] > newInterval[1]) {
                        if(!added) res.push_back(newInterval);
                        res.push_back(cur_range);
                        added = true;
    
                    }
                    else if (cur_range[1] < newInterval[0]) {
                        res.push_back(cur_range);
                    }
                    else{ 
                        int beg = min(cur_range[0], newInterval[0]);
                        int end = max(cur_range[1], newInterval[1]);
                        newInterval = {beg, end};
                    }
            }
    
            if(!added) res.push_back(newInterval);
            return res;
        }
        
};