t = int(input())
for test in range(t):
	n = int(input())
	s = ""
	for i in range(n):
		s += input()

	letters =list(set(s))

	res = True
	for i in range(len(letters)):
		if s.count(letters[i]) % n != 0:
			res = False

	if res:
		print("YES")
	else:
		print("NO")