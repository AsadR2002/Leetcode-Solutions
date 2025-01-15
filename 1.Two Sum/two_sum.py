class Solution(object):
    def twoSum(self, nums, target):
        numMap = {}
        ans = []

        for i in range(len(nums)):
            if target - nums[i] in numMap:
                return [numMap[target-nums[i]], i]
            else:
                numMap[nums[i]] = i
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        