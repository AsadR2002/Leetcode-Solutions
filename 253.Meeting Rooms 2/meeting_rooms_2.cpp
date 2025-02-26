/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

 class Solution {
    public:
        int minMeetingRooms(vector<Interval>& intervals) {
            vector<vector<int>> map; 
            for(Interval intv : intervals) {
                map.push_back({intv.start, 1});
                map.push_back({intv.end, -1});
            }
    
            sort(map.begin(), map.end()); 
    
            int max_count = 0; 
            int ongoing = 0;
            for(int i = 0; i < map.size(); i++){
                ongoing += map[i][1];
                max_count = max(max_count, ongoing);
    
            }
    
            return max_count;   
        }
};
    