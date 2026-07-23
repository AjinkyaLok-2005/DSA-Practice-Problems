from typing import List

class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = 0
        right = n - 1

        while left < right:
            if nums[left] % 2 == 0:
                left += 1
            elif nums[right] % 2 != 0:
                right -= 1
            else:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1

        return nums

if __name__ == "__main__":
    nums = list(map(int, input("Enter the array elements: ").split()))

    obj = Solution()

    result = obj.sortArrayByParity(nums)

    print("Array after sorting by parity: ")
    print(result)