import sys

# with open('input.txt', 'r') as sys.stdin:
N = int(input())
Q = []

for i in range(0, N):
    S = str(input())
    split = S.split(' ')
    command = split[0]
    parameter = None
    if len(split) == 2:
        parameter = split[1]
    if command == "push":
        Q.append(parameter)
    elif command == "pop":
        if len(Q) != 0:
            print(Q[0])
            Q.pop(0)
        else:
            print(-1)
    elif command == "size":
        print(len(Q))
    elif command == "empty":
        if len(Q) == 0:
            print(1)
        else:
            print(0)
    elif command == "front":
        if len(Q) == 0:
            print(-1)
        else:
            print(Q[0])
    elif command == "back":
        if len(Q) == 0:
            print(-1)
        else:
            print(Q[-1])
