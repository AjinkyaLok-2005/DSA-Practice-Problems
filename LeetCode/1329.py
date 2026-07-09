from typing import List
from collections import defaultdict

class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        mp = defaultdict(List)

        for i in range(m):
            for j in range(n):
                mp[i-j].append(mat[i][j])

        for key in mp:
            mp[key].sort()

        for i in range(m -1, -1, -1):
            for j in range(n-1, -1, -1):
                mat[i][j] = mp[i-j].pop()

        return mat
    

if __name__ == "__main__":
    mat = [
        [3, 3, 1, 1],
        [2, 2, 1, 2],
        [1, 1, 1, 2]
    ]

    sol = Solution()
    result = sol.diagonalSort(mat)

    for row in result:
        print(row)