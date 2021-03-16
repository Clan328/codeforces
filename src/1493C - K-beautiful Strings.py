def is_valid(s, k):
	st = list(set(s))

	for i in range(len(st)):
		if s.count(st[i]) % k != 0:
			return False
	return True

def inc(s):
	s = list(s)

	s[-1] = chr(ord(s[-1])+1)
	i = 1
	while s[-i] == "{" and i <= len(s):
		s[-i] = "a"
		s[-(i+1)] = chr(ord(s[-(i+1)])+1)
		i+=1

	return "".join(s)

t = int(input())
for case in range(t):
	n, k = map(int, input().split())
	s = input()

	if n % k != 0:
		print(-1)
	else:
		res = s[0:n]
		i = 1
		while True:
			if res < s:
				print(-1)
				break
			if is_valid(res, k):
				print(res)
				break
			else:
				res = inc(res)