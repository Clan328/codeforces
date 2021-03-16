s = input()
for i in range(len(s)-6):
	if (s[i:i+7] == "0000000" or s[i:i+7] == "1111111"):
		print("YES")
		break
else:
	print("NO")