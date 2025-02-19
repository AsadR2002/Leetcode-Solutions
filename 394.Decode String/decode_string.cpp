class Solution {
    public:
        string decodeString(string s) {
            stack<string> res;  // Stack to store intermediate results
            string ans = "";
    
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != ']') {
                    res.push(string(1, s[i]));  // Convert char to string before pushing
                } 
                else {
                    string substr = "";
                    while (!res.empty() && res.top() != "[") {
                        substr = res.top() + substr;
                        res.pop();
                    }
                    res.pop(); 
    
                    string k = "";
                    while (!res.empty() && isdigit(res.top()[0])) { 
                        k = res.top() + k;
                        res.pop();
                    }
    
                    int num = stoi(k);
                    string repeated = "";
                    for (int j = 0; j < num; j++) {
                        repeated += substr;
                    }
                    res.push(repeated);
                }
            }
    
            while (!res.empty()) {
                string temp = res.top();  
                ans = temp + ans;
                res.pop();
            }
            return ans;
        }
    };
    