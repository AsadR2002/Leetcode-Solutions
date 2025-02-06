class Solution(object):
    def majorityElement(self, nums):
        count = 1
        cand = nums[0]
        for i in range(1, len(nums)):
            if count == 0:
                cand = nums[i]
            if nums[i] == cand:
                count +=1
            else:
                count-=1
        return cand
        """
        :type nums: List[int]
        :rtype: int
        """
        