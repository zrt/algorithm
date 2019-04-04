s = input()
a = ''
l = len(s)
for i in range(len(s)):
	if i & 1 ^ (l&1):
		a += s[0]
		s = s[1:]
	else:
		a += s[-1]
		s = s[:-1]

print(a[::-1])