class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        pt1, pt2 = m - 1, n - 1 # pointers for nums1 and nums2, respectively. starting from the end
        pt3 = m + n - 1         # pointer for the new vector

        while pt2 >= 0:
            # comparing and merge
            if pt1 < 0:
                nums1[pt3] = nums2[pt2]
                pt2 -= 1
            else:
                if nums2[pt2] >= nums1[pt1]:
                    nums1[pt3] = nums2[pt2]
                    pt2 -= 1
                else:
                    nums1[pt3] = nums1[pt1]
                    pt1 -= 1

            pt3 -= 1