import sys

sys.stdin = open("D:\Projects\AA\BOJ\\6604\input.txt", "r")
input = sys.stdin.readline

N = int(input().strip())

matrices = {}

for i in range(N):
    temp = input().rstrip().split()
    name = temp[0]
    dim = temp[1:]
    dim = list(map(int, dim))
    matrices[name] = dim


line = input().rstrip()
while line != "":
    stack = []
    count = 0
    temp_matrices = {}
    for char in line:
        if char == '(':
            None
        elif char == ')':
            char1 = stack.pop()
            char2 = stack.pop()
            b = temp_matrices[char1]
            a = temp_matrices[char2]
            if a[1] != b[0]:
                print("error")
                break
            count = count + a[0] * a[1] * b[1]
            temp_matrices[char2][1] = b[1]
            stack.append(char2)
        else:
            temp_matrices[char] = []
            temp_matrices[char].append(matrices[char][0])
            temp_matrices[char].append(matrices[char][1])
            stack.append(char)
    else:
        print(count)
    line = input().rstrip()
