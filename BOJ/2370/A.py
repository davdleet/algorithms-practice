import sys

sys.stdin = open('D:\Projects\AA\BOJ\\2370\input.txt', 'r')
input = sys.stdin.readline

N = int(input().rstrip())

d = {}
lines = []
wall = []
posters = {}


def add_pos(n, s, e):
    m = (s+e) // 2
    if s > e:
        return s
    if wall[m][0] == n:
        return -1
    elif wall[m][0] > n:
        return add_pos(n, s, m-1)
    else:
        return add_pos(n, m+1, e)


for i in range(N):
    l, r = map(int, input().rstrip().rsplit())
    lines.append((l, r))
    p1 = 0
    p2 = 0
    p1 = add_pos(l, 0, len(wall) - 1)
    if p1 != -1:
        wall.insert(p1, [l, -1])
    p2 = add_pos(r, 0, len(wall) - 1)
    if p2 != -1:
        wall.insert(p2, [r, -1])

for i in range(len(wall)):
    d[wall[i][0]] = i

end = 0
for i in range(0, len(lines)):
    l = lines[i][0]
    r = lines[i][1]
    s = d[l]
    e = d[r]
    end = e
    for j in range(d[l], d[r]+1):
        wall[j][1] = i

print(wall)
print(lines)
for i in range(len(wall)):
    p = wall[i][1]
    if(p != -1):
        posters[p] = i
cnt = len(posters)

print(cnt)
