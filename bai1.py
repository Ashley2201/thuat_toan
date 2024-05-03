import math

def soUoc(n) :
    dem = 0
    for i in range (1, int(n/2 + 1)) :
        if(n % i == 0) : dem = dem + 1
        if(dem > 3) : return False
    if(dem == 3): return True

def qPrime(n) :
    for i in range(6, n):
        if(soUoc(i) == True) :
            print(i)

qPrime(15)