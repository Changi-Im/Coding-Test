class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        sp, ep = 0, len(nums) - 1
        k = 0

        # 0. return 0 if num.length < 0
        if ep < 0: return 0

        # 1. find val in nums and change it to -1
        for i in range(len(nums)):
            if nums[i] == val:
                nums[i] = -1
            else:
                k += 1

        # 2. move endpoint until element is not -1
        while nums[ep] < 0:
            ep -= 1
            if ep < 0: return 0
        
        # 3. swap elements between startpoint and endpoint
        while sp <= ep:
            if nums[sp] < 0:
                nums[sp] = nums[ep]
                nums[ep] = -1
                while nums[ep] < 0:
                    ep -= 1
            
            sp += 1
        
        # 4. return k
        return k
