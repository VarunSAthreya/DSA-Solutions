class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        adj = {u: [] for u in range(n)}
        for f in flights:
            adj[f[0]].append((f[1], f[2]))
            
        Q = []
        Q.append((0, src, K+1))
        
        while len(Q) > 0:
            top = heapq.heappop(Q)
            d, u, e = top
            if dst == u :
                return d
            if e > 0:
                for v in adj[u]:
                    heapq.heappush(Q, (d + v[1], v[0], e-1))
        return -1