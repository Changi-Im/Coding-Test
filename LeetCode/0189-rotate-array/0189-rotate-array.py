class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # initial start point
        sp = 0

        # shift start point
        while k > 0:
            sp -= 1
            if sp < 0:
                sp = len(nums) - 1
            k -= 1

        # save shifted elements into tmp
        if sp != 0:
            tmp1 = [nums[i] for i in range(sp, len(nums))]
            tmp2 = [nums[i] for i in range(0, sp)]
            tmp = tmp1 + tmp2

            for i in range(len(nums)):
                nums[i] = tmp[i]