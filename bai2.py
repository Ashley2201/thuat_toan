import math

def sNT(n):
    if(n < 2): return False
    if(n == 2): return True
    for i in range(2, int(math.sqrt(n)) + 1):
        if(n % i == 0): return False
    return True

def timSNT(n):
    for i in range(int(math.pow(10, n-1)), int(math.pow(10, n) - 1)):
        if(sNT(i) == True): print(i)

if __name__ == "__main__":
    timSNT(2)