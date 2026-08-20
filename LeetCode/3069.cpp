from typing import List


class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1 = [nums[0]]
        arr2 = [nums[1]]

        for i in range(2, len(nums)):
            if arr1[-1] > arr2[-1]:
                arr1.append(nums[i])
            else:
                arr2.append(nums[i])

        return arr1 + arr2


if __name__ == "__main__":
    # Example test cases
    test_cases = [
        [2, 1, 3],
        [5, 4, 3, 8],
    ]

    sol = Solution()
    for nums in test_cases:
        result = sol.resultArray(nums)
        print(f"Input: {nums} -> Output: {result}")