s = """###  ..#  ###  ###  #.#  ###  ###  ###  ###  ###
#.#  ..#  ..#  ..#  #.#  #..  #..  ..#  #.#  #.#
#.#  ..#  ###  ###  ###  ###  ###  ..#  ###  ###
#.#  ..#  #..  ..#  ..#  ..#  #.#  ..#  #.#  ..#
###  ..#  ###  ###  ..#  ###  ###  ..#  ###  ###"""

compare = [_.split() for _ in s.split('\n')]
given = [input().split() for _ in range(5)]
ans = ""

for i in range(4):
    for num in range(10):
        is_possible = True
        
        for row_idx in range(5):
            s1 = compare[row_idx][num]
            s2 = given[row_idx][i]
            
            for j in range(3):
                if s1[j] == '.' and s2[j] == '#':
                    is_possible = False
                    break
            if not is_possible:
                break
        
        if is_possible:
            ans += str(num)
            break

print(ans[:2] + ":" + ans[2:])                