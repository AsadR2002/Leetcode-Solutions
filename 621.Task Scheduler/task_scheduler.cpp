class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            priority_queue<pair<int, char>> maxHeap; 
    
            unordered_map<char, int> freq;
        
            // Count occurrences
            for (char c : tasks) {
                freq[c]++;
            }
        
            for(auto [c, n]: freq){
                maxHeap.push({n, c});
            }
    
            int time = 0; 
    
            queue<pair<int, int>> q;
    
            while(!maxHeap.empty() || (!q.empty())){
                time++;
    
                if(!maxHeap.empty()) {
                    int cnt = maxHeap.top().first - 1; 
                    char c =  maxHeap.top().second; 
                    maxHeap.pop();
                    if(cnt) q.push({cnt, time + n});
    
                }
    
                if(!q.empty() && q.front().second == time) {
                    maxHeap.push({q.front().first, 'A'});
                    q.pop();
                }
            }
    
            return time;
        }
};