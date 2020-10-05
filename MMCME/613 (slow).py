# https://informatics.mccme.ru/mod/statements/view3.php?chapterid=613

n = int(input())
nums = list(map(int, input().split()))
lens = [1]*n
prev = [-1]*n
#нахождение максимальной длины возростающей подпоследовательности
#   для каждого элемента
for i in range(n):
    for j in range(i):
        if nums[j]<nums[i] and lens[j]+1>lens[i]:
            lens[i] = lens[j]+1
            prev[i] = j

ans = []
k = lens.index(max(lens))
while k != -1:
    ans.append(nums[k])
    k = prev[k]
    
#вывод ответа
ans = ans[::-1]
s = ""
for i in ans:
    s = s + str(i) + " "
print(len(ans))
print(s)
