n = int(input())
s = []
for i in range(2*n-2):
	s.append(input().strip())

x,y = [x for x in s if len(x) == n-1]

def check(x,y,s,n):
	full = x+y[-1]
	taga = [0]*(n)
	tagb = [0]*(n)
	result = [0]*(2*n-2)
	for i in range(len(s)):
		p = s[i]
		if full.startswith(p) and taga[len(p)] == 0:
			taga[len(p)] = 1
			result[i] = 'P'
		elif full.endswith(p) and tagb[len(p)] == 0:
			tagb[len(p)] = 1
			result[i] = 'S'
	if 0 in result:
		return False,result
	return True,result


r,rr =check(x,y,s,n)
if r:
	# print(rr)
	print(''.join(rr))
else:
	r,rr = check(y,x,s,n)
	# print(rr)
	print(''.join(rr))

