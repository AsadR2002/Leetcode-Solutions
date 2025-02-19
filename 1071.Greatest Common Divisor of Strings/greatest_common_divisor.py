class Solution(object):
    def gcdOfStrings(self, str1, str2):
        len1, len2 = len(str1), len(str2)

        def isDivisor(l):
            if len1 % l or len2% l:
                return False
            f1, f2 = len1 // l, len2 // l
            if str1[:l] * f1 == str1 and str1[:l] * f2 == str2:
                return True 
            

        for l in range(min(len1, len2), 0, -1):
            if isDivisor(l):
                return str1[:l]
        return ""
        
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        