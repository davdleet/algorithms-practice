import sys

sys.stdin = open("D:\Projects\AA\BOJ\\2448\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

ans = ""
end = ""
five = "*****"
two = "* *"
one = "*"
cnt = 0
for i in range(N):
    num = i // 3
    if i % 3 == 0:
        line = ""
        line += end
        li = [five] * num
        line += " ".join(li)
        line += end
        ans += line
        ans += "\n"
    else:
        line = ""
        line += end
        temp = "*" * i
        line += temp
        line += end
        ans += line
        ans += "\n"
    end += " "

print(ans)
