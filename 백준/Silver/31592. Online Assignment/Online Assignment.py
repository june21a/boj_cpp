lst = ['f', 'f', 'f', 'f', 'f']
print(''.join(lst), flush=True)
s = input().strip()

if s != 'completed':
    _, last_cnt = s.split()
    last_cnt = int(last_cnt)
    
    for i in range(5):
        lst[i] = 't'
        print(''.join(lst), flush=True)
        
        s = input().strip()
        if s == 'completed':
            break
        _, cnt = s.split()
        cnt = int(cnt)
        
        if cnt > last_cnt:
            last_cnt = cnt
        else:
            lst[i] = 'f'