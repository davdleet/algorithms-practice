import sys
from math import sqrt
sys.stdin = open("D:\Projects\AA\BOJ\\4386\input.txt")

N = int(input().rstrip())

coord = []
parent = [i for i in range(N+1)]
edges = []

for i in range(N):
    line = list(map(float, input().rstrip().split()))
    a = line[0]
    b = line[1]
    coord.append([a, b, i+1])


for i in range(N):
    x = coord[i][0]
    y = coord[i][1]
    s = coord[i][2]
    for j in range(i+1, N):
        x1 = coord[j][0]
        y1 = coord[j][1]
        s1 = coord[j][2]
        dis = sqrt((x1-x) ** 2 + (y1-y) ** 2)
        edges.append([dis, s, s1])

edges.sort()


def find(child):
    if parent[child] == child:
        return child
    else:
        parent[child] = find(parent[child])
        return parent[child]


def union(a, b):
    parent_a = find(a)
    parent_b = find(b)
    parent[parent_b] = parent[parent_a]


sum = 0
added = 0
for i in range(len(edges)):
    if added == N-1:
        break
    a = edges[i][0]
    b = edges[i][1]
    c = edges[i][2]
    if(find(b) == find(c)):
        continue
    else:
        union(b, c)
        sum += a

print("{:.2f}".format(sum))
