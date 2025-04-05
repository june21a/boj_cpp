s = input().rstrip()

lst = list(s.split('-'))

for i, formula in enumerate(lst):
    inner_lst = list(formula.split('+'))
    total = 0
    
    for num in inner_lst:
        total = total + int(num)
    lst[i] = total


total = int(lst[0])
for i in range(1, len(lst)):
    total = total - lst[i]

print(total)