n = int(input())
x1 = 0
x2 = 0
y3 = 0
for i in range(n):
    x, y = map(int, input().split())
    if y == 0:
        if x >= x2:
            x2 = x
        elif x <= x1:
            x1 = x
    if abs(y) > y3:
        y3 = y
s = 0.5*(x2-x1)*abs(y3)

print(s)
