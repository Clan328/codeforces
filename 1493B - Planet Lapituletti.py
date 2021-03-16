t = int(input())
for case in range(t):
	h, m = map(int, input().split())
	s = input()

	hs = int(s[0:2])
	ms = int(s[3:5])

	valid = {0: 0, 1: 1, 2: 5, 5: 2, 8: 8}

	while True:
		if (hs % 10 in valid) and (hs // 10 in valid) and (ms % 10 in valid) and (ms // 10 in valid) and valid[ms%10]*10 + valid[ms//10] < h and valid[hs%10]*10 + valid[hs//10] < m:
			print(str(hs // 10) + str(hs % 10) + ":" + str(ms//10) + str(ms%10))
			#print(str(valid[ms % 10]) + str(valid[ms//10]) + ":" + str(valid[int(hs%10)]) + str(valid[int(hs//10)]))
			break
		else:
			ms+=1
			if ms >= m:
				ms = 0
				hs+=1
				if hs >= h:
					hs = 0
