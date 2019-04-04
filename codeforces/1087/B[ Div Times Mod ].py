n,k = map(int,input().split())
mn = 10**100 
for i in range(1,k):
	xdk = n//i
	if xdk * i == n :
		mn = min(mn,xdk*k+i)
print(mn)
