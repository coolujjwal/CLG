t = int(input())

while t > 0:
	t -= 1
	n,k,x,y = map(int,input().split())
	c = True
	j = x
	for i in range(0,n):
		if(j%n == y):
			c = False
			break
		j += k
	if c:
		print("NO")
		continue
	print("YES")

	