
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

def last_digit_square(n):
    pp = pinaso_period(10)
    r = n % pp
    t = fibonacci(r)
    return t % 10

n = input()
ans1 = last_digit_square(int(n))
ans2 = last_digit_square(int(n)+1)
print ((ans1*ans2)%10)