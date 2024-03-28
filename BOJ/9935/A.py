import sys
sys.stdin = open("D:\Projects\AA\BOJ\9935\input.txt")
input = sys.stdin.readline
S = str(input().rstrip())
bomb = str(input().rstrip())
st = S
l = len(bomb)
result = ""
i = 0
while i <= len(st)-l:
    test = st[i:i+l]
    j = i
    while test == bomb:
        st = st[0:j] + st[j+l:]
        j = i - l
        if j < 0:
            j = 0
        test = st[j:j+l]
    i = j
    i = i + 1

if st == "":
    print("FRULA")
else:
    print(st)
