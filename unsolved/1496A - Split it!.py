import math

def is_valid(s, a, k):
	temp = "".join(a)
	i = k-1
	while i >= 0:
		rev = "".join(list(reversed(a[i])))
		temp += rev
		i-=1
	return s == temp

t = int(input())
for case in range(t):
	n, k = map(int, input().split())
	s = input()

	res = False
	"""
	if k < 1:
		res = True
	elif (n+k) % 2 == 0:
		new = []
		for i in range(k+1):
			new.append( s[i * k: k * k +1])
		new.append(s[k*k-1:k*k+k])
		for i in range(k+1, 0):
			new.append( s[i * k : k * k+1])
		print("".join(new))
		print(new)
		if new == s:
			res = True
	"""

	if k < 1:
		res = True


	print(is_valid("ioi", ["i", "o"], k))
	"""

	if res:
		print("YES")
	else:
		print("NO")"""