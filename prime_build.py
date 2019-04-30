def build_items():
    t=1
    while True:
        t=t+2
        yield t
def prime_list():
    yield 2
    it=build_items()
    while True:
        n=next(it)
        yield n
        it=filter(lambda x:x%n>0, it)

for i in prime_list():
    if i<300:
        print(i)
    else:
        break
