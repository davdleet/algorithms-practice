import sys

sys.stdin = open("D:\Projects\AA\BOJ\9375\input.txt")
input = sys.stdin.readline

T = int(input().rstrip())
for i in range(T):
    d = {}
    wear = {}
    cnt = 0
    N = int(input().rstrip())
    for j in range(N):
        nm, tp = input().rstrip().split()

        try:
            chk = wear[tp]
            wear[tp].append(nm)
        except:
            wear[tp] = [nm]
    for key in wear.keys():
        l = len(wear[key])
        cnt = cnt + l + cnt * l
    # for key in wear.keys():
    #     t = list(d.keys())
    #     for ex in t:
    #         d[ex+key] = 1
    #     for item in wear[key]:
    #         d[item] = 1
    print(cnt)
