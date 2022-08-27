
import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1918\input.txt")
input = sys.stdin.readline

line = list(input().rstrip())

st = []


def higher(a, b):
    aval = 0
    bval = 0

    if a == '*' or a == '/':
        aval = 2
    else:
        aval = 1
    if b == '*' or b == '/':
        bval = 2
    else:
        bval = 1
    if aval == bval:
        return -1
    elif aval > bval:
        return 1
    else:
        return 0


for c in line:
    if c.isalpha():
        print(c, end='')
    else:
        if c == '(':
            st.append(c)
        elif c == ')':
            top = st[-1]
            while top != '(':
                print(top, end='')
                st.pop()
                top = st[-1]
            st.pop()
        else:

            if not len(st) or st[-1] == '(':
                st.append(c)
            else:
                # make a comparison with new operand with top
                compare = higher(st[-1], c)
                # top of stack is higher
                if compare == 1:
                    while(len(st) and st[-1] != '('):
                        print(st[-1], end='')
                        st.pop()
                    st.append(c)
                # same
                elif compare == -1:
                    print(st[-1], end='')
                    st.pop()
                    st.append(c)
                # top of stack is lower
                else:
                    st.append(c)
while len(st):
    print(st[-1], end='')
    st.pop()
