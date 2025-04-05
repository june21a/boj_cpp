import sys
input = sys.stdin.readline

T = int(input())
for i in range(T):
    N, M, K = map(int, input().split())
    
    if N < 2*K and M < 2*K:
        print("Yuto")
        continue
    
    if (N*M) % 2:
        print("Yuto")
    else:
        print("Platina")