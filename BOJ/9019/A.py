import sys
from collections import deque

sys.stdin = open('D:\Projects\AA\BOJ\9019\input.txt')
input = sys.stdin.readline
T = int(input().rstrip())

for i in range(T):
    ch = [10**6] * 10000
    start, end = map(int, input().rstrip().split())
    ans = ''
    q = deque([(start, '')])
    times = 0
    while q:
        times += 1
        current = q.popleft()
        num = current[0]
        ins = current[1]
        if num == end:
            ans = ins
            break
        a1 = (num * 2) % 10000
        a2 = ins + 'D'
        if len(a2) < ch[a1]:
            q.append((a1, a2))
            ch[a1] = len(a2)
        b1 = 0
        if num == 0:
            b1 = 9999
        else:
            b1 = num - 1
        b2 = ins + 'S'
        if len(b2) < ch[b1]:
            q.append((b1, b2))
            ch[b1] = len(b2)
        zeros = '0' * (4 - len(str(num)))
        new_str = zeros + str(num)
        c1 = new_str[1:] + new_str[0]
        c2 = ins + 'L'
        if len(c2) < ch[int(c1)]:
            q.append((int(c1), c2))
            ch[int(c1)] = len(c2)
        d1 = new_str[3] + new_str[0:3]
        d2 = ins + 'R'
        if len(d2) < ch[int(d1)]:
            q.append((int(d1), d2))
            ch[int(d1)] = len(d2)
    print(ans)
