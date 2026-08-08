class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        V = len(graph)

        adj = [[] for _ in range(V)]

        que = deque()

        outdegree = [0] * V

        count = 0

        for u in range(V):
            for v in graph[u]:
                adj[v].append(u)
                outdegree[u] += 1

        for i in range(V):
            if outdegree[i] == 0:
                que.append(i)
                count += 1

        safe = [False] * V

        while que:
            u = que.popleft()
            safe[u] = True

            for v in adj[u]:
                outdegree[v] -= 1
                if outdegree[v] == 0:
                    que.append(v)
                    count += 1

        return [i for i in range(V) if safe[i]]