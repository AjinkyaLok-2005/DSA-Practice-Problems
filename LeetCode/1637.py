from typing import List

class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        n = len(points)

        points.sort()

        result = 0

        for i in range(1, n):
            width = points[i][0] - points[i-1][0]
            result = max(result, width)

        return result

if __name__ == "__main__":
    points = [[8, 7], [9, 9], [7, 4], [9, 7]]
    sol = Solution()
    print(sol.maxWidthOfVerticalArea(points))