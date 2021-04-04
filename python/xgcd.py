def extendedGcd(b, a):
   #return (g, x, y) such that a*x + b*y = g = gcd(a, b)
    x0, x1, y0, y1 = 0, 1, 1, 0
    q = 0
    print "q, b, a, x0, x1, y0, y1: ",q, b, a, x0, x1, y0, y1 
    while a != 0:  #prime
        q, b, a = b // a, a, b % a

        y0, y1 = y1, y0 - q * y1
        x0, x1 = x1, x0 - q * x1
        print "q, b, a, x0, x1, y0, y1: ",q, b, a, x0, x1, y0, y1
    return b, x0, y0
print "ANS: ",extendedGcd(5,8)[2]