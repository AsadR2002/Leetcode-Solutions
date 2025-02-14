class Solution {
public:
    int strStr(string haystack, string needle) {
        int start = 0; 
        int currDig = 0;
        int needleptr = 0; 

        while(start < haystack.size()) {
            //check if curr char starts needle 
            //if so, keep iterating
            if(haystack[start] == needle[needleptr]) {
                currDig = start + 1; 
                needleptr++; 
                while(start < haystack.size() && needleptr <  needle.size()) {
                    if(haystack[currDig] == needle[needleptr]) {
                        currDig++; 
                        needleptr++;
                    }
                    else {
                        start++; 
                        needleptr = 0;
                        break;
                    }
                }
                if (needleptr == needle.size()) {
                    return start;
                }
            }
            else {
                start++;
            }

        }
        return -1;
        
    }
};