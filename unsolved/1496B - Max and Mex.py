import math

t = int(input())
for case in range(t):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))

	for i in range(k):
		mex = 0
		x = 0
		while True:
			if x not in a:
				mex = x
				break
			else:
				x+=1
		a.append(math.ceil( (max(a)+mex)/2) )

	print(len(set(a)))