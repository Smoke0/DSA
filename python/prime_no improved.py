# This is a better program to print prime no.s upto n
n=int(input())

prime=list()
prime.append(2)
for i in range(3,n+1):
    for j in prime:
        if i%j == 0:
            break
    else:
        prime.append(i)
print(' '.join(str(x) for x in prime))