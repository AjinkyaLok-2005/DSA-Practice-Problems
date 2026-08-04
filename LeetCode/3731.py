from typing import List


class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        nums.sort()

        n = len(nums)
        first = nums[0]
        last = nums[n - 1]

        i = 1
        num = first + 1

        ans = []

        while num != last:
            if i < n and num == nums[i]:
                i += 1
            else:
                ans.append(num)

            num += 1

        return ans


if __name__ == "__main__":
    # Input the elements separated by spaces
    nums = list(map(int, input("Enter the numbers: ").split()))

    sol = Solution()
    result = sol.findMissingElements(nums)

    print("Missing elements:", result)