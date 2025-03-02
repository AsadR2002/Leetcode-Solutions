class Solution {
    public:
        string reorganizeString(string s) {
            priority_queue<pair<int, char>> maxHeap; 
            
            unordered_map<char, int> freq;
    
            // Count occurrences
            for (char c : s) {
                freq[c]++;
            }
    
            for(auto [c, n]: freq){
                maxHeap.push({n, c});
            }
    
            pair<int, char> prev = {0, '#'}; 
    
            string res = "";
    
            while(!maxHeap.empty() || prev.second != '#') {
                if(maxHeap.empty() && prev.second != '#') return "";
                int cnt = maxHeap.top().first; 
                char c =  maxHeap.top().second; 
                maxHeap.pop();
                res += c;
                if(prev.second != '#') {
                    maxHeap.push(prev);
                }
                prev = {0, '#'}; 
                if(cnt > 1) {
                    prev.first = cnt - 1; 
                    prev.second = c;
                }
    
            }
            return res;
        }
};