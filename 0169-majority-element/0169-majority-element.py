class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        table = {}
        for n in nums:
            if table.get(n, False):
                table[n] += 1
            else:
                table[n] = 1
            
            if table[n] > len(nums) // 2:
                return n