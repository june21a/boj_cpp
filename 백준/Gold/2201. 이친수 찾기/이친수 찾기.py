K = int(input())

DP = [-1 for i in range(1000)]
DP[0] = 1
DP[1] = 2
for i in range(2, 1000):
    DP[i] = DP[i-1] + DP[i-2]

pinary_len = 0
a=0; b=1; s = 0
while s < K:
    s += b
    a, b = b, a+b
    pinary_len += 1


ans = ""
for l in range(pinary_len-1, -1, -1):
    if DP[l] <= K:
        ans += '1'
        K-= DP[l]
    else:
        ans += '0'
print(ans)