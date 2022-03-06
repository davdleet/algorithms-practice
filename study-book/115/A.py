import sys

sys.stdin = open("D:\Projects\AA\study-book\\115\input.txt")
input = sys.stdin.readline

line = input().rstrip()
a = ord(line[0]) - ord('a')
n = int(line[1])-1

moves = [(-2, 1), (-2, -1), (2, 1), (2, -1), (1, 2),
         (1, -2), (-1, 2), (-1, -2)]

count = 0
for i in range(len(moves)):
    move = moves[i]
    x = move[0]
    y = move[1]
    rx = a + x
    ry = a + y
    if rx > 7 or rx < 0 or ry > 7 or ry < 0:
        continue
    count += 1
print(count)
