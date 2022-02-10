import sys

sys.stdin = open('D:\Projects\AA\BOJ\\1182\input.txt')
input = sys.stdin.readline

N, S = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
check = [False] * N
count = 0


def solve(num):
    global count
    if num == N:
        sum = 0
        if check == [False] * N:
            return
        for i in range(len(check)):
            if check[i]:
                sum += arr[i]
        if sum == S:
            count += 1
    else:
        check[num] = True
        solve(num+1)
        check[num] = False
        solve(num+1)


solve(0)
print(count)
