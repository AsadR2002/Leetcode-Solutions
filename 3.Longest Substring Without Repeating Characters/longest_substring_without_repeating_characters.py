class Solution(object):
    def lengthOfLongestSubstring(self, s):
        maxlen = 0
        sett = set()
        l = 0

        for r in range(len(s)):
            while s[r] in sett:
                sett.remove(s[l])
                l += 1
            sett.add(s[r])
            maxlen = max(maxlen, r-l+1)
        return maxlen
            
        """
        :type s: str
        :rtype: int
        """