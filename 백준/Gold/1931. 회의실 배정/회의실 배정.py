import sys

N = int(sys.stdin.readline())
confTime = []

for i in range(N):
    a, b = list(map(int, sys.stdin.readline().split()))
    confTime.append((a, b))

confTime.sort(key=lambda x: (x[1], x[0]))

last = 0
cnt = 0
for i in confTime:
    if i[0] >= last:
        last = i[1]
        cnt += 1

print(cnt)