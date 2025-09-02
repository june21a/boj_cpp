import sys

input = sys.stdin.readline

def get_value(x, x1, y1, x2, y2):
    if x1 == x2:
        return [y1, y2] if y1<y2 else [y2, y1]
    else:
        return (y2-y1) / (x2-x1) * (x-x1) + y1

def interval_intersection(interval1, interval2):
    a, b = interval1
    c, d = interval2
    start = max(a, c)
    end = min(b, d)
    if start <= end:
        return [start, end]  # 교집합 구간
    else:
        return None          # 교집합 없음


eps = 1e-6
x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

if x1 == x2 and x3 == x4:
    if x1 == x3:
        v1 = get_value(x1, x1, y1, x2, y2)
        v2 = get_value(x3, x3, y3, x4, y4)
        res = interval_intersection(v1, v2)
        if res is None:
            print(0)
        elif res[1] == res[0]:
            print(1)
            print(f"{x1:.10f} {res[0]:.10f}")
        else:
            print(1)
    else:
        print(0)
elif x1 == x2:
    v1 = get_value(x1, x1, y1, x2, y2)
    v2 = get_value(x1, x3, y3, x4, y4)
    if v1[0]-eps < v2 < v1[1]+eps and min(x3, x4) <= x1 <= max(x3, x4):
        print(1)
        print(f"{x1:.10f} {v2:.10f}")
    else:
        print(0)
elif x3 == x4:
    v1 = get_value(x3, x1, y1, x2, y2)
    v2 = get_value(x3, x3, y3, x4, y4)
    if v2[0]-eps < v1 < v2[1]+eps and min(x1, x2) <= x3 <= max(x1, x2):
        print(1)
        print(f"{x3:.10f} {v1:.10f}")
    else:
        print(0)
else:
    s1 = (y2-y1) / (x2-x1)
    s2 = (y4-y3) / (x4-x3)
    
    if abs(s1-s2) < eps:
        c1 = y1 - s1*x1
        c2 = y3 - s2*x3
        if(abs(c1-c2) < eps):
            if max(x1, x2) == min(x3, x4):
                print(1)
                print(f"{max(x1, x2):.10f} {get_value(max(x1, x2), x1, y1, x2, y2):.10f}")
            elif min(x1, x2) == max(x3, x4):
                print(1)
                print(f"{min(x1, x2):.10f} {get_value(min(x1, x2), x1, y1, x2, y2):.10f}")
            elif max(x1, x2) < min(x3, x4) or min(x1, x2) > max(x3, x4):
                print(0)
            else:
                print(1)
        else:
            print(0)
    else:
        x = (s2*x3 - s1*x1 + y1 - y3) / (s2-s1)
        if max(min(x1, x2), min(x3, x4))-eps < x < min(max(x1, x2), max(x3, x4))+eps:
            y = get_value(x, x1, y1, x2, y2)
            print(1)
            print(f"{x:.10f} {y:.10f}")
        else:
            print(0)