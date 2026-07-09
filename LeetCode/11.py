from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)

        i = 0
        j = n-1

        maxWater = 0

        while i < j:
            w = j - i
            h = min(height[i], height[j])

            area = w * h

            maxWater = max(maxWater, area)

            if height[i] > height[j]:
                j -= 1
            else:
                i += 1

        return maxWater
    

if __name__ == "__main__":
    height = [1, 8, 6, 2, 5, 4, 8, 3, 7]

    obj = Solution()
    print(obj.maxArea(height))
