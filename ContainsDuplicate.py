class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) == 0:
            return False
        nums_dict = {}
        for i in nums:
            if nums_dict.get(i, 0) == 0:
                nums_dict[i] = 1
            else:
                return True
        return False
                    
        
