import math

def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a%b)

A, B, C, D = map(int, input().split())
g = gcd(A, B)
if D % g:
    print("No solution.")
else:
    x = 0
    y = math.ceil(C/B)
    while True:
        if A*x - B*y == D:
            break
        elif A*x - B*y < D:
            x += 1
        else:
            y += 1
    
    truck = f"{x} truck"
    boat = f"{y} boat"
    if x != 1:
        truck += 's'
    if y != 1:
        boat += 's'
    print(f"We need {truck} and {boat}.")