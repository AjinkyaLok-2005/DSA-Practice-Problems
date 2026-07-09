class Solution:
    def minimumCost(self, cost: list[int]) -> int:
        n = len(cost)

        cost.sort(reverse = True)

        minCost = 0

        for i in range(n):
            if i % 3 != 2: #skip every 3rd candy
                minCost += cost[i]

        return minCost
    

if __name__ == "__main__":
    cost = [6, 5, 7, 9, 2, 2]

    obj = Solution()
    print(obj.minimumCost(cost))