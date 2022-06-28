import sys

sys.stdin = open("D:\Projects\AA\BOJ\\16928\input.txt")
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())

shortcuts = [0 for i in range(0, 101)]
dis = [100000 for i in range(0, 101)]
current = 1

for i in range(N+M):
    S, E = map(int, input().rstrip().split())
    shortcuts[S] = E


def BFS():
    q = []
    q.append((1, 0))
    while(len(q)):
        current = q[0][0]
        dices = q[0][1]
        if len(q) == 1:
            q.pop()
        else:
            q = q[1:]
        if shortcuts[current]:
            q.append((shortcuts[current], dices))
            dis[shortcuts[current]] = dices
        else:
            for i in range(1, 7):
                if (current+i < 101) and dis[current+i] > dices+1:
                    q.append((current+i, dices+1))
                    dis[current+i] = dices+1


BFS()
print(dis[100])
