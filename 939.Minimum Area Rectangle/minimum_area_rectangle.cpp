class Solution {
    public:
        int minAreaRect(vector<vector<int>>& points) {
            int min = INT_MAX;
            set<pair<int, int>> visited; 
    
            for(auto p: points) {
                int x1 = p[0], y1 = p[1];
                for(auto p2: visited) {
                    int x2 = p2.first, y2 = p2.second;
                    if(visited.find({x1, y2}) != visited.end() && visited.find({x2, y1}) != visited.end()) {
                        int size = abs(x2-x1) * abs(y2 - y1);
                        if(size < min) min = size;
                    }
                }
                visited.insert({x1, y1});
            }
            if(min == INT_MAX) min = 0;
            return min; 
        }
};