import sys

sys.stdin = open('D:\Projects\AA\BOJ\\7568\input.txt')
input = sys.stdin.readline

N = int(input().rstrip())

arr = [()] * N
placement = [0] * N
for i in range(N):
    arr[i] = tuple(map(int, input().rstrip().split()))

for i in range(N):
    current = arr[i]
    w = current[0]
    h = current[1]
    count = 0
    for j in range(i+1, N):
        if w < arr[j][0] and h < arr[j][1]:
            count += 1
        elif w > arr[j][0] and h > arr[j][1]:
            placement[j] = placement[j] + 1
        else:
            None
    placement[i] = placement[i] + count
for i in range(len(placement)):
    placement[i] = placement[i] + 1
    print(placement[i], end=' ')
