class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 2:
            return len(nums)
        
        s, f = 2, 2 # fast and slow pointer
        while f < len(nums):
            if nums[s-2] != nums[f]:
                nums[s] = nums[f]
                s += 1
            f += 1

        return s