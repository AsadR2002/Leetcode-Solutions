class Solution(object):
    def isPalindrome(self, s):
        cleaned = ''.join(char.lower() for char in s if char.isalnum())
        if cleaned == "":
            return True 
        left = 0
        right = len(cleaned) - 1
        while left < right: 
            if cleaned[left] == cleaned[right]:
                left+=1 
                right -=1 
            else: 
                return False 
        return True 
        """
        :type s: str
        :rtype: bool
        """
        