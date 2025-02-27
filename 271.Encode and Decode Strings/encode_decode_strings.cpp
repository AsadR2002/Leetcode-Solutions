class Solution {
    public:
    
        string encode(vector<string>& strs) {
            string limiter = "-";
            string ans ="";
            for(string s: strs) {
                ans += s; 
                ans += limiter;
            }
            return ans; 
        }
    
        vector<string> decode(string s) {
            vector<string> output; 
            string temp = ""; 
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '-') {
                    output.push_back(temp); 
                    temp= "";
                }
                else {
                    temp += s[i];
                }
            }
            return output; 
        }
};
    