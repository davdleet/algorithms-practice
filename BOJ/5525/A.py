import sys

sys.stdin = open(
    '/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/5525/input.txt', 'r')

N = int(input())
M = int(input())
S = input()
# print(N)
# print(M)
# print(S)
T = ''
for i in range(0, N):
    T = T + 'IO'
T = T + 'I'
C = ''
cnt = 0
idx = 0
while(True):
    idx = S.find(T, idx)
    if(idx == -1):
        break
    cnt = cnt + 1
    next_idx = idx+len(T)
    while(next_idx <= len(S)-2 and S[next_idx:next_idx+2] == "OI"):
        cnt = cnt+1
        next_idx = next_idx + 2
    idx = next_idx


print(cnt)
