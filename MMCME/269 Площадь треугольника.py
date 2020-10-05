# Задача №269. Площадь треугольника
# https://informatics.mccme.ru/mod/statements/view3.php?id=1156&chapterid=269#1

a = list(map(int, input().split()))
x = [a[0]] + [a[2]] + [a[4]]
y = [a[1]] + [a[3]] + [a[5]]
for i in range(len(x)):
    for j in range(len(x)):
        if x[i] < x[j]:
            x[i], x[j] = x[j], x[i]
            y[i], y[j] = y[j], y[i]
s1 = (y[0] + y[1]) * abs(x[1] - x[0])
s2 = (y[1] + y[2]) * abs(x[2] - x[1])
s3 = (y[0] + y[2]) * abs(x[2] - x[0])
s0 = abs(s1 + s2 - s3)
print(s0/2)

