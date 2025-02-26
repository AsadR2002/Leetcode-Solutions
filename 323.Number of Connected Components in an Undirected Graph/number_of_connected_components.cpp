class Solution {
    public:
        unordered_map<int, vector<int>> map; 
        set<int> nums; 
    
        void dfs(int index) {
            if(nums.find(index) != nums.end()) return;
            nums.insert(index); 
            for(int c: map[index]) {
                dfs(c);
            }
        }
        int countComponents(int n, vector<vector<int>>& edges) {
            int count = 0; 
            int index =0; 
    
            for(auto& edge : edges) {
                int a = edge[0]; 
                int b = edge[1];
                map[a].push_back(b);
                map[b].push_back(a);
            }
            
            while(nums.size() != n) {
                while(nums.find(index) != nums.end()) index++; 
                dfs(index); 
                count++;
            }
            return count; 
        }
};
    