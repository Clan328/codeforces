import random

n = 10**5
m = 10**5
with open("input.txt", "w") as f:
	f.write(str(n) + " " + str(m) + "\n")
	"""for i in range(1, m+1):
		k = random.randint(0, n)
		f.write(str(k) + " ")
		for i in range(1, k+1):
			f.write(str(random.randint(1, n))+ " ")
		f.write("\n")"""