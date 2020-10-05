# http://acmp.ru/index.asp?main=task&id_task=39
n = int(input())
a = input().split()
k = 0
ans = 0
prev = 0
m = int(a[0])
for i in range(0, n):
	if int(a[i])>m:
		k = i
		m = int(a[i])
ans += (k + 1) * m
prev = k
#print(k + 1, "*", m)

while k != n-1:
	prev = k
	k += 1
	m = int(a[k])
	for i in range(k, n):
		if int(a[i])>m:
			k = i
			m = int(a[i])
	#print(k - prev, "*", m)
	ans += (k - prev) * m
print(ans)
