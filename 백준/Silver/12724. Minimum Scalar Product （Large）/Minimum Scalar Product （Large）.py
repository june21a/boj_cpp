import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    L = int(input())
    v1 = sorted(list(map(int, input().split())))
    v2 = sorted(list(map(int, input().split())), reverse=True)
    print(f"Case #{_+1}: {sum([i*j for i, j in zip(v1, v2)])}")