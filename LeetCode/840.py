from typing import List

class Solution:
    def isMagicSquare(self, grid: List[List[int]], r: int, c: int):
        st = set()

        for i in range(3):
            for j in range(3):
                num = grid[r+i][c+j]
                
                if num < 1 or num > 9 or num in st:
                    return False
                
                st.add(num)

        SUM = grid[r][c] + grid[r][c + 1] + grid[r][c + 2]

        # Row and Column
        for i in range(3):
            if grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != SUM:
                return False

            if grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != SUM:
                return False

        # diagonals
        if grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != SUM:
            return False

        if grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != SUM:
            return False

        return True

    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        count = 0

        for i in range(rows - 2):
            for j in range(cols - 2):
                if self.isMagicSquare(grid, i, j):
                    count += 1

        return count
    

if __name__ == "__main__":
    grid = [
        [4, 3, 8, 4],
        [9, 5, 1, 9],
        [2, 7, 6, 2]
    ]

    sol = Solution()
    result = sol.numMagicSquaresInside(grid)
    print("Number of Magic Squares in the grid: ", result)
    