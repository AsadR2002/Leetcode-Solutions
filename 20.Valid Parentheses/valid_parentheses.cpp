class Solution {
    public:
        bool isValid(string s) {
            vector<char> opening = {'[', '(', '{'};
            vector<char> closing = {']', ')', '}'};
    
            stack<char> callStack; 
    
            for(char c : s) { 
                if(find(opening.begin(), opening.end(), c) != opening.end()) {
                    callStack.push(c);
                }
                else {
                    if(callStack.empty()) return false;
                    char bracket = callStack.top(); 
                    callStack.pop();
                    if((find(opening.begin(), opening.end(), bracket) - opening.begin()) != (find(closing.begin(), closing.end(),c) - closing.begin())) {
                        return false;
                    }
                }
            }
    
            if (!callStack.empty()) return false;
    
            return true;
            
        }
    };