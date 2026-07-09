from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)

        result = [1] * n

        for i in range(1, n):
            result[i] = result[i-1] * nums[i - 1]

        right_pdt = 1

        for i in range(n-1, -1 , -1):
            result[i] *= right_pdt
            right_pdt *= nums[i]


        return result
    

if __name__ == "__main__":
    nums = list(map(int, input("Enter the elements of the array: ").split()))

    sol = Solution()

    result = sol.productExceptSelf(nums)