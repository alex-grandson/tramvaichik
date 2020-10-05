
left = int(input())
right = int(input())
if left <= 2 and 2 <= right:
    print(2)
for i in range(left, right + 1):
    if (2 ** (i - 1)) % i == 1:
        print(i)
else:
    print("Absent")
