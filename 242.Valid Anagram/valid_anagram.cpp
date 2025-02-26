class Solution {
    public:
        bool isAnagram(string s, string t) {
            unordered_map<char, int> char_list;
    
            if(t.length() != s.length()) return false;
    
            for(int i = 0; i < s.length(); i++) {
                if(char_list.find(s[i]) != char_list.end()) char_list[s[i]]++;
                else char_list[s[i]] = 1;
    
                if(char_list.find(t[i]) != char_list.end()) char_list[t[i]]--;
                else char_list[t[i]] = -1;
            }
    
            for(const auto& [key, value] : char_list) {
                if(value) return false;
            }
            return true;
        }
};