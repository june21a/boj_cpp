N, M = map(int, input().split())
graph = [[] for i in range(N+1)]
for i in range(M):
    a, b, c, d = map(int, input().split())
    graph[a].append((b, c, d))

t = [[], [], []]
def dfs(node, cost, line):
    if node == N:
        t[line].append(cost)
        return
    
    for i in range(len(graph[node])):
        dfs(graph[node][i][0], cost + graph[node][i][line], line)
    return
dfs(1, 0, 1)
dfs(1, 0, 2)

t1 = sorted(t[1])
t2 = t[2]
ans = "IMPOSSIBLE"
for t in t1:
    if t in t2:
        flag = True
        ans = t
        break
print(ans)