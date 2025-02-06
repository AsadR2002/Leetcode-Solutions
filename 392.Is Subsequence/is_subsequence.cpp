class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lpt = 0; 
        int tpt = 0;

        while(lpt < s.size() && tpt < t.size()) {
            if(s[lpt] == t[tpt]) lpt++; 

            tpt++;
        }
        if(lpt == s.size()) return true; 
        return false;
    }
};