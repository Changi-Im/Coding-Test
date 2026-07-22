class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # sort the array
        nums.sort()

        return nums[len(nums)//2]
