from typing import List

class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        restrictions.append([1, 0])
        restrictions.append([n, n-1])

        restrictions.sort()

        N = len(restrictions)

        for i in range(1, N):
            diff_dist = restrictions[i][0] - restrictions[i - 1][0]
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + diff_dist
            )

        for i in range(N-2, -1, -1):
            diff_dist = restrictions[i + 1][0] - restrictions[i][0]
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + diff_dist
            )

        result = 0

        for i in range(1, N):
            left_pos = restrictions[i - 1][0]
            left_ht = restrictions[i - 1][1]

            curr_pos = restrictions[i][0]
            curr_ht = restrictions[i][1]

            d = curr_pos - left_pos
            ht_diff = abs(left_ht - curr_ht)

            peak = max(left_ht, curr_ht) + (d - ht_diff) // 2

            result = max(result, peak)

        return result
    

if __name__ == "__main__":
    n = 5
    restrictions = [[2, 1], [4, 1]]

    sol = Solution()
    print(sol.maxBuilding(n, restrictions))