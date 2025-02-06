class Solution(object):
    def isSubsequence(self, s, t):
        lpt, tpt = 0, 0
            
        while tpt < len(t) and lpt < len(s):
            if t[tpt] == s[lpt]:
                lpt+=1 

            tpt += 1
        return lpt == len(s)