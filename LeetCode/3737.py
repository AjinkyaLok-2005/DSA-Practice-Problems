class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)

        answer = 0

        for i in range(n):
            count = 0

            for j in range(i, n):
                if nums[j] == target:
                    count += 1

                size = j - i + 1

                if count > size // 2:
                    answer += 1

        return answer


if __name__ == "__main__":
    nums = [2, 1, 2]
    target = 2

    sol = Solution()
    print(sol.countMajoritySubarrays(nums, target))