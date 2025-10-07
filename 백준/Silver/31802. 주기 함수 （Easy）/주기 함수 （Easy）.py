import sys
input = sys.stdin.readline

N = int(input())
lst = list(map(int, input().split()))
a, b = map(int, input().split())
cumsum = [0]
for num in lst:
    cumsum.append(cumsum[-1] + num)
print((cumsum[b%N]) + (cumsum[-1] - cumsum[a%N]) + cumsum[-1] * ((b - a - b%N - (N-a%N)) // N))