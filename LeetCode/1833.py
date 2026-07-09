from typing import List

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()

        count = 0

        for cost in costs:
            if cost > coins:
                return count
            else:
                count += 1
                coins -= cost


            return count

if __name__ == "__main__":
    costs = [1, 3, 2, 4, 1]
    coins = 7

    sol = Solution()
    print(sol.maxIceCream(costs, coins))  # Output: 4