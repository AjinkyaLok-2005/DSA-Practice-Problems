from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        Sum = 0
        maxi = nums[0]
        n = len(nums)

        for i in range(n):
            Sum = Sum + nums[i]

            maxi = max(maxi, Sum)

            if(Sum < 0):
                Sum = 0

        return maxi
        

if __name__ == "__main__":
    nums = list(map(int, input("Enter the elements of the array: ").split()))

    sol = Solution()
    result = sol.maxSubArray(nums)

    print("Maximum Subarray Sum: ", result)