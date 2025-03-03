class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> res; 
    
            if(p.length() > s.length()) return res;
    
            unordered_map<char, int> pCount;
            unordered_map<char, int> sCount;
    
            for(int i = 0; i < p.length(); i++) {
                if(pCount.find(p[i]) != pCount.end()) pCount[p[i]]++;
                else pCount[p[i]] = 1;
                
                if(sCount.find(s[i]) != sCount.end()) sCount[s[i]]++; 
                else sCount[s[i]] = 1;
            }
    
            if(sCount == pCount) res.push_back(0); 
    
    
            int l = 0; 
            for(int r = p.length(); r < s.length(); r++) {
                if(sCount.find(s[r]) != sCount.end()) sCount[s[r]]++; 
                else sCount[s[r]] = 1;
                sCount[s[l]]--; 
    
                if(sCount[s[l]] == 0) sCount.erase(s[l]);
                l++;
                if(sCount == pCount) res.push_back(l); 
            }
    
            return res;
            
        }
};