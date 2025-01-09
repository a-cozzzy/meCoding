class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        zero_count = 0
        longest_window = 0
        start = 0

        for i in range(len(nums)):
            zero_count += (nums[i] == 0)
                          
            while zero_count > 1:
                zero_count -= (nums[start] == 0)
                start += 1
              
            longest_window = max(longest_window, i - start)
        
        return longest_window   
        