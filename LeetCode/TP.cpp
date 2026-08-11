from collections import defultdict, deque

class Solution:

    def isCyclisBFS(self, src, visited, adj):
        parent = {}
        parent[src] = -1

        visited[src] = True

        q = deque()
        q.append(src)

        while q:
            front = q.popleft()

            for neighbour in adj[front]:
                if visited[neighbour] and neighbour != parent[front]:
                    return True

                elif not visited[neighbour]:
                    q.append(neighbour)
                    visited[neighbour] = True
                    parent[neighbour] = front

        return False

    def isCyclicDFS(self, node, parent, visited, adj):
        visited[node] = True

        for neighbour in adj[node]:
            if not visited[neighbour]:
                cycleDetected = self.DFS(neighbour, node, visited, adj)

                if cycleDetected:
                    return True

            elif neighbour != parent:
                return True

        return False

    def cycleDetection(self, edges, n, m):
        #adj = defaultdict(list)
        adj = [[] for _ in range(n)]

        for i in range(m):
            u = edges[i][0]
            v = edges[i][1]

            adj[u].append(v)
            adj[v].append(u)

        visited = [False] * n

        for i in range(n):
            if not visited[i]:
                ans = self.isCyclicDFS(i, -1, visited, adj)
                # ans = self.isCyslicBFS(i, visited, adj)

                if ans:
                    return "Yes"

        return "No"
