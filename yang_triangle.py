def yang_tri():
	L=[1]
	while True:
		yield L
		L=[1]+[L[i]+L[i+1] for i in range(len(L)-1)]+[1]
	return 'done'
g = yang_tri()

for i in range(8):
	next(g)
print(next(g))
