import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1863\input.txt", )
input = sys.stdin.readline

N = int(input().rstrip())

max_y = 0
stack = []
count = 0
for i in range(N):
    x, y = map(int, input().rstrip().split())
    if len(stack) == 0 or stack[-1] < y:
        stack.append(y)
    elif stack[-1] != y:
        while len(stack) != 0 and stack[-1] > y:
            stack.pop()
            count += 1
        if len(stack) == 0 or stack[-1] < y:
            stack.append(y)
while len(stack) != 0:
    if stack[-1] != 0:
        count += 1
    stack.pop()
print(count)
