s = input()
n = len(s)
res = sum(int(s[i]) for i in range(n) if s[i] == s[(i + n // 2) % n])
print(res)
