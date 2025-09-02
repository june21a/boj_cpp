N = int(input())
R, C = map(int, input().split())

if N <= 2:
    print(1)
elif N == 3:
    if R == 2 and C == 2:
        print(1)
    else:
        print(4)
else:
    print(N*N // 2 + ((R+C) % 2 == 0 and N % 2 == 1))