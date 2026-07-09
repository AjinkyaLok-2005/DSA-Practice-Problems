from typing import List

class Solution:
    def findFinishTime(self, start1: List[int], duration1: List[int], start2: List[int], duration2: List[int]) -> int:
        finish1 = float('inf')

        for i in range(len(start1)):
            finish1 = min(finish1, start1[i] + duration1[i])

        finish2 = float('inf')

        for j in range(len(start2)):
            finish2 = min(finish2, max(finish1, start2[j]) + duration2[j])

        return finish2

    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        firstLand_thenWater = self.findFinishTime()

        firstWater_thenLand = self.findFinishTime()

        return min(firstLand_thenWater, firstWater_thenLand)
    


if __name__ == "__main__":
    landStartTime = [2, 8]
    landDuration = [4, 1]
    waterStartTime = [6]
    waterDuration = [3]

    sol = Solution()
    print(sol.earliestFinishTime(
        landStartTime,
        landDuration,
        waterStartTime,
        waterDuration    
    ))