from typing import List


class Solution:
    directions = [(1, 0), (-1, 0), (0, -1), (0, 1)]

    def DFS(self, grid, i, j, m, n):
        if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != '1':
            return

        grid[i][j] = '$'

        for dr, dc in self.directions:
            i_ = i + dr
            j_ = j + dc
            self.DFS(grid, i_, j_, m, n)

    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        islands = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    self.DFS(grid, i, j, m, n)
                    islands += 1

        return islands


if __name__ == "__main__":
    grid = [
        ['1', '1', '1', '1', '0'],
        ['1', '1', '0', '1', '0'],
        ['1', '1', '0', '0', '0'],
        ['0', '0', '0', '0', '0']
    ]

    sol = Solution()
    result = sol.numIslands(grid)

    print("Number of Islands:", result)