from collections import defaultdict

class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        mp = defaultdict(int)

        cumSum = 0
        mp[0] = 1
        
        validLeftPoints = 0
        result = 0

        for num in nums:
            if num == target:
                validLeftPoints += mp[cumSum]
                cumSum += 1
            else:
                cumSum -= 1
                validLeftPoints -= mp[cumSum]

            mp[cumSum] += 1
            result += validLeftPoints

        return result
    
if __name__ == "__main__":
    nums = [2, 1, 2]
    target = 2

    sol = Solution()
    print(sol.countMajoritySubarrays(nums, target))