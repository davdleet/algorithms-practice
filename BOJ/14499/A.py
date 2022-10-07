import sys

sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/14499/input.txt")
input = sys.stdin.readline

top = 0
bottom = 0
left = 0
right = 0
front = 0
back = 0

dir = [[0, 1], [0, -1], [-1, 0], [1, 0]]


def moveE():
    global top, bottom, left, right, front, back
    new_top = left
    new_bottom = right
    new_right = top
    new_left = bottom
    top = new_top
    bottom = new_bottom
    right = new_right
    left = new_left


def moveW():
    global top, bottom, left, right, front, back
    new_top = right
    new_bottom = left
    new_right = bottom
    new_left = top
    top = new_top
    bottom = new_bottom
    right = new_right
    left = new_left


def moveN():
    global top, bottom, left, right, front, back
    new_top = back
    new_bottom = front
    new_front = top
    new_back = bottom
    top = new_top
    bottom = new_bottom
    front = new_front
    back = new_back


def moveS():
    global top, bottom, left, right, front, back
    new_top = front
    new_bottom = back
    new_front = bottom
    new_back = top
    top = new_top
    bottom = new_bottom
    front = new_front
    back = new_back


first_line = list(map(int, input().rstrip().split()))
N = first_line[0]
M = first_line[1]
x = first_line[2]
y = first_line[3]
K = first_line[4]
arr = []

for i in range(N):
    line = list(map(int, input().rstrip().split()))
    arr.append(line)

instructions = list(map(int, input().rstrip().split()))
print(instructions)
for ins in instructions:
    a = dir[ins-1][0]
    b = dir[ins-1][1]
    if x + a < 0 or x + a >= N or y + b < 0 or y+b >= M:
        continue
    if ins == 1:
        moveE()
    elif ins == 2:
        moveW()
    elif ins == 3:
        moveN()
    else:
        moveS()
    # floor number is 0
    if arr[x+a][y+b] == 0:
        arr[x+a][y+b] = bottom
    # floor number is not 0
    else:
        bottom = arr[x+a][y+b]
        arr[x+a][y+b] = 0
    x = x + a
    y = y + b
    print(top)
