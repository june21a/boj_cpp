import sys
from collections import deque
input = sys.stdin.readline

X, Y, Mx, My = map(int, input().split())
Mx -= 1
My = Y-My
farm = [[c for c in input().strip()] for _ in range(Y)]
farm[My][Mx] = 'M'
q = deque([(My, Mx, 0)])
d = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]


while q:
    y, x, depth = q.popleft()
    ans = depth
    
    for dy, dx in d:
        next_y, next_x = dy+y, dx+x
        
        if next_y < 0 or next_y >= Y or next_x < 0 or next_x >= X or farm[next_y][next_x] == '*' or farm[next_y][next_x] =='M':
            continue
        farm[next_y][next_x] = 'M'
        q.append((next_y, next_x, depth+1))
print(depth)