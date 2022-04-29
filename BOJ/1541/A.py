import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1541\input.txt")
input = sys.stdin.readline

exp = input().rstrip()
paren = False
start = False
i = 0
while i != len(exp):
    if not paren and exp[i] == '-':
        start = False
        paren = True
        exp = exp[:i+1] + '(' + exp[i+1:]
        i += 1
    elif paren and (exp[i] == '-'):
        start = False
        exp = exp[:i] + ')' + exp[i] + '(' + exp[i+1:]
        paren = True
        i += 2
    elif paren and (i == len(exp) - 1):
        start = False
        exp = exp + ')'
        paren = False
        i += 1
    else:
        if not start and exp[i] == '0':
            exp = exp[:i] + exp[i+1:]
            i -= 1
        elif exp[i] == "+":
            start = False
        else:
            start = True
    i += 1
print(eval(exp))
