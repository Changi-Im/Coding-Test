class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # empty list to save non-duplicated elements
        l = []

        # push non-duplicated elements into the list
        tmp = nums[0]
        l.append(tmp)
        for i in range(1, len(nums)):
            if tmp != nums[i]:
                tmp = nums[i]
                l.append(tmp)

        # change nums elements according to the list
        for i in range(len(l)):
            nums[i] = l[i]

        return len(l)