
def fibonacci(n):
    f = list()
    f = [0,1]
    for i in range(2,n+1):
        f.append(f[i-1] + f[i-2])
    return f[n]

def pinaso_period(m):
    previous,current = 0,1
    p = 0
    while(True):
        p += 1
        previous,current = current, (previous + current) % m
        if (previous == 0 and current == 1):
            break
    return p

def modulo(n,m):
    pp = pinaso_period(10)
    r1 = (n+2) % pp
    r2 = (m+1) % pp;
    t1 = fibonacci(r1)
    t2 = fibonacci(r2)
    return (t1-t2) % 10

m,n =  (input()).split(" ")
ans = modulo(int(n),int(m))
print (ans)