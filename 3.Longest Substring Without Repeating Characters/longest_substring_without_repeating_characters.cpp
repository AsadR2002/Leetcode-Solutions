class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0; 
        std::set <char> letter_set; //set 
        int l = 0; //initialize left pointer 

        for(int r = 0; r < s.length(); r++)
        {
            while(letter_set.contains(s[r])) { //if character in set already
                letter_set.erase(s[l]); //shift left pointer and remove char from set 
                l++; 
            }
            letter_set.insert(s[r]); //new letter that is part of substring 
            maxlen = max(maxlen, r-l+1); //solution is max of current length substring and max 
        }
        return maxlen;
    }
};