class Solution {
    public:
        unordered_map<int, vector<int>> preMap;
        unordered_set<int> visitSet; 
    
        bool dfs(int crs) {
            if(visitSet.find(crs) != visitSet.end()) return false; 
    
            if (preMap[crs].empty()) return true;
    
            visitSet.insert(crs); 
    
            for(int pre: preMap[crs]) {
                if(!dfs(pre)) return false; 
            }
            visitSet.erase(crs); 
            preMap[crs].clear();
            return true; 
        }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            for(vector<int> prereq: prerequisites) {
                 preMap[prereq[0]].push_back(prereq[1]);
            }
    
            for(int i = 0; i < numCourses; i++) {
                if(!dfs(i)) return false; 
            }
            return true; 
        }
};