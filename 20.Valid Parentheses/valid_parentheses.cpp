class Solution {
    public:
        bool isValid(string s) {
            stack<char> bracket;
            unordered_map<char, char> pairs; 
    
            pairs['('] = ')';
            pairs['{'] = '}';
            pairs['['] = ']'; 
    
            
            for(int i = 0; i < s.length(); i++) {
                if(pairs.find(s[i]) != pairs.end()) {
                    bracket.push(s[i]); 
                }
                else {
                    if(bracket.empty()) return false;
                    char opening = bracket.top(); 
                    if(pairs[opening] != s[i]) return false;
                    bracket.pop();
                }
            }
    
            return bracket.empty();
    
        }
};