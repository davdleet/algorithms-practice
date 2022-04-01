import sys
from collections import deque

sys.stdin = open("D:\Projects\AA\BOJ\9019\input.txt")
input = sys.stdin.readline

T = int(input().rstrip())
ch = [100000] * 10000

for i in range(T):
    start, end = map(int, input().rstrip().split())
    ans = ''
    cnt = 10**6
    st = deque([(start, '', 0)])
    times = 0
    while st:
        times += 1
        current = st.popleft()
        num = current[0]
        ins = current[1]
        sh = current[2]
        if num == end:
            if len(ins) < cnt:
                ans = ins
            break
        a1 = (num * 2) % 10000
        a2 = ins + 'D'
        if len(a2) < ch[a1] and a2 != current:
            st.append((a1, a2, 0))
            ch[a1] = len(a2)
        b1 = 0
        if num == 0:
            b1 = 9999
        else:
            b1 = num - 1
        b2 = ins + 'S'
        if len(b2) < ch[b1]:
            st.append((b1, b2, 0))
            ch[b1] = len(b2)
        new_str = str(num)
        if len(str(num)) < 4:
            to_add = '0' * (4 - len(str(num)))
            new_str = to_add + str(num)
        if sh <= 2:
            c1 = new_str[1:] + new_str[0]
            c2 = ins + 'L'
            if len(c2) < ch[int(c1)]:
                st.append((int(c1), c2, sh+1))
                ch[int(c1)] = len(c2)
            if sh < 2:
                d1 = new_str[3] + new_str[0:3]
                d2 = ins + 'R'
                if len(d2) < ch[int(d1)]:
                    st.append((int(d1), d2, sh+1))
                    ch[int(d1)] = len(d2)
        cnt += 1
    print(ans)
