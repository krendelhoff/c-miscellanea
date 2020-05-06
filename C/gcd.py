def gcd(a, b):
    if a == 0:
        return (b)
    return (gcd(b % a, a))

def ring(n):
    i = 1
    counter = 0
    while (i < n):
        if (gcd(i, n) == 1):
            counter += 1
        i += 1
    return (counter)

def main():
    print(ring(103484))

main()
