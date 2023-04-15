# python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        table = dict()
        for index, value in enumerate(nums):
            if (table.get(target - value) != None):
                return [ table.get(target - value), index ]
            table[value] = index
        return []

# python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = dict()
        for index, value in enumerate(nums):
            if (table.get(target - value) != None):
                return [ table.get(target - value), index ]
            table[value] = index
        return []
    
