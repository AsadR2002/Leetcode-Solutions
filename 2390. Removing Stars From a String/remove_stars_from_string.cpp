class Solution {
    public:
        string removeStars(string s) {
            string result;
            for (char c : s) {
                if (c == '*') {
                    if (!result.empty()) {
                        result.pop_back();  // Efficient O(1) removal from the end
                    }
                } else {
                    result.push_back(c); // Efficient O(1) append
                }
            }
            return result;
        }
    };