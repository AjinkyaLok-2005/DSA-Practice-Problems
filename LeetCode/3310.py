from typing import List


class Solution:
    def DFS(self, node, adj, suspicious):
        suspicious[node] = True

        for neighbour in adj[node]:
            if not suspicious[neighbour]:
                self.DFS(neighbour, adj, suspicious)

    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]

        for a, b in invocations:
            adj[a].append(b)

        suspicious = [False] * n

        self.DFS(k, adj, suspicious)

        for a, b in invocations:
            if not suspicious[a] and suspicious[b]:
                return [i for i in range(n)]

        return [i for i in range(n) if not suspicious[i]]


if __name__ == "__main__":
    n = 4
    k = 1
    invocations = [
        [1, 2],
        [0, 1],
        [3, 2]
    ]

    sol = Solution()
    ans = sol.remainingMethods(n, k, invocations)

    print("Remaining Methods:", ans)