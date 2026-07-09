from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:        
        max_c = max(candies)

        result = [False] * len(candies)

        for i in range(len(candies)):
            if candies[i] + extraCandies >= max_c:
                result[i] = True

        return result


# Example usage
candies = [2, 3, 5, 1, 3]
extraCandies = 3

sol = Solution()
answer = sol.kidsWithCandies(candies, extraCandies)

print(answer)




