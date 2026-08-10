from typing import List
from collections import defaultdict, deque


class Solution:
    def findAllRecipes(
        self,
        recipes: List[str],
        ingredients: List[List[str]],
        supplies: List[str]
    ) -> List[str]:

        n = len(recipes)

        st = set(supplies)

        # adj[ingredient] = recipes that need this ingredient
        adj = defaultdict(list)

        indegree = [0] * n

        for i in range(n):
            for ing in ingredients[i]:
                if ing not in st:
                    adj[ing].append(i)
                    indegree[i] += 1

        que = deque()

        for i in range(n):
            if indegree[i] == 0:
                que.append(i)

        result = []

        while que:
            front = que.popleft()

            recipe = recipes[front]
            result.append(recipe)

            for idx in adj[recipe]:
                indegree[idx] -= 1

                if indegree[idx] == 0:
                    que.append(idx)

        return result


if __name__ == "__main__":
    recipes = ["bread", "sandwich"]
    ingredients = [
        ["yeast", "flour"],
        ["bread", "meat"]
    ]
    supplies = ["yeast", "flour", "meat"]

    solution = Solution()

    result = solution.findAllRecipes(
        recipes,
        ingredients,
        supplies
    )

    print(result)