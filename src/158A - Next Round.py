n, k = map(int, input().split())
a = list(map(int, input().split()))

res = 0
for i in range(n):
	if a[i] >= a[k-1] and a[i] > 0:
		res+=1

print(res)