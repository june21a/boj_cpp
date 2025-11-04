import sys
from collections import deque
input = sys.stdin.readline
MOD  = 1000000007

N, M = map(int, input().split())
cnts = [0 for _ in range(N+1)]
graph = [[] for _ in range(N+1)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)


q = deque([(1, 1)])
cnts[1] = 1
while q:
    cur, t = q.popleft()
    
    for next_node in graph[cur]:
        if cnts[next_node]:
            continue
        cnts[next_node] = t+1
        q.append((next_node, t+1))


d = {}
for i in range(1, N+1):
    if cnts[i] in d:
        d[cnts[i]] += 1
    else:
        d[cnts[i]] = 1

ans = 1
for v in d.values():
    ans = (ans * (v+1)) % MOD
print((ans-1) % MOD)