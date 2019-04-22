
def f(x):
	return x * x
n = int(input())
l = []
for i in range(n):
	tmp = int(input())
	l.append(tmp)

r = map(f,l)

list(r)

