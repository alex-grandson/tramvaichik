# 612 Выражения
# https://informatics.msk.ru/mod/statements/view3.php?id=634&chapterid=612#1
n, s = map(int, input().split())
a = list(map(int, input().split()))
for i in range(2 ** (n - 1)):
    b = bin(i)[2::]
    b = '0' * (n - 1 - len(b)) + b
    t = a[0]
    for j in range(len(b)):
        if b[j] == '0':
            t += a[j + 1]
        else:
            t -= a[j + 1]
    if t == s:
        ans = str(a[0])
        for j in range(len(b)):
            if b[j] == '0':
                ans += '+'
            else:
                ans += '-'
            ans += str(a[j + 1])
        ans += '=' + str(s)
        print(ans)
        exit()
print('No solution')
