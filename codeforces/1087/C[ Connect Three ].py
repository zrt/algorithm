p = []
p.append(list(map(int,input().split())))
p.append(list(map(int,input().split())))
p.append(list(map(int,input().split())))


ans = []
for k in [0,1]:
	p = sorted(p,key=lambda x:x[k])
	while p[0][k] != p[1][k]:
		ans.append(tuple(p[0]))
		p[0][k] +=1

	while p[1][k] != p[2][k]:
		ans.append(tuple(p[2]))
		p[2][k] -=1

ans.append(p[0])
print(len(ans))
for x in ans:
	print('%d %d'%(x[0],x[1]))
