import itertools
import sys

input = sys.stdin.readline

n = int(input())

results = []
for comb in itertools.combinations(range(5), 2):
    arr = [0] * 5
    for i in comb:
        arr[i] = 1
    results.append(tuple(arr))

d = {
    res: 0 for res in results
}

for i in range(n):
    days = list(map(int, input().split()))
    for k in d.keys():
        cnt = 0
        for j in range(5):
            if k[j] == 1 and days[j] == 1:
                cnt += 1
        if cnt >= 2:
            d[k] += 1

ans_key = (0,0,0,1,1)
for k, v in d.items():
    if v > d[ans_key]:
        ans_key = k

print(d[ans_key])
for i in ans_key:
    print(i, end=' ')