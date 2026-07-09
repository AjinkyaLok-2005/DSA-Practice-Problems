from typing import List
from collections import defaultdict

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0])

        result = []
        mp = defaultdict(list)

        for i in range(m):
            for j in range(n):
                mp[i+j].append(mat[i][j])

        for key in sorted(mp.keys()):
            if key % 2 == 0:
                mp[key].reverse()

                for x in mp[key]:
                    result.append(x)

        return result
    
if __name__ == "__main__":
    # Input dimensions
    m = int(input("Enter number of rows: "))
    n = int(input("Enter number of columns: "))

    # Input matrix
    print("Enter the matrix:")
    mat = []
    for i in range(m):
        row = list(map(int, input().split()))
        mat.append(row)

    # Create object
    obj = Solution()

    # Get diagonal traversal
    result = obj.findDiagonalOrder(mat)

    # Print result
    print("Diagonal Traversal:")
    print(result)