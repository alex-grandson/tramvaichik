def notContainNums(s):
    for i in range(len(s)):
        if s[i]>='0' and s[i]<='9':
            return True
    else:
        return False

s = input()
i = 0
while (notContainNums(s)):
    while (s[i] != ')'):
        i+=1
    while (s[i] != '('):
        i-=1
    s = s[0:i] + s[i+1:]
    num = ""
    sub = ""
    while s[i]>='0' and s[i]<='9':
        num += s[i]
        s = s[0:i] + s[i+1:]
    while s[i] != ')':
        sub += s[i]
        s = s[0:i] + s[i+1:]
    s = s[0:i] + int(num)*sub + s[i+1:]
print(s)
