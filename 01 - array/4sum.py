# Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
# 0 <= a, b, c, d < n
# a, b, c, and d are distinct.
# nums[a] + nums[b] + nums[c] + nums[d] == target
# You may return the answer in any order.

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if not nums or len(nums) < 4:
            return []
        
        res = []
        nums.sort()
        
        for i in range(len(nums) - 3):
            # skip duplicates
            if i > 0 and nums[i] == nums[i - 1]:
                continue
                
            for j in range(i + 1, len(nums) - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                    
                two_sum = nums[i] + nums[j]
                
                l, r = j + 1, len(nums) - 1
                
                while l < r:
                    four_sum = two_sum + nums[l] + nums[r]
                    
                    if four_sum == target:
                        res.append([nums[i], nums[j], nums[l], nums[r]])
                        
                        l += 1
                        # take care of duplicates
                        while l < r and nums[l] == nums[l - 1]:
                            l += 1
                        
                        r -= 1                       
                        while l < r and nums[r] == nums[r + 1]:
                            r -= 1
                            
                    elif four_sum > target:
                        r -= 1
                        
                    else:
                        l += 1                
                              
        return res
                        
                        
