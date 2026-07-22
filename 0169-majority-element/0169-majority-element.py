class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # sort the array
        nums.sort()

        # count elements using two pointers
        sp, ep = 0, 0
        cnt = 0
        while ep < len(nums):
            if nums[sp] == nums[ep]:
                cnt += 1
            else:
                sp = ep
                cnt = 1
            ep += 1

            if cnt > len(nums) // 2:
                return nums[sp]
                
