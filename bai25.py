import math
import array
def SNT(n):
    if n < 2: return False
    if n < 4: return True
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0: return False
    return True

def tach(n, m, kq, arr, vitri):
    if n == 0 and m == 0:
        print(kq)
        return
    if vitri == -1: return
    for i in range(vitri, -1, -1):
        if n >= arr[i]:
            so = str(arr[i])
            tem = kq
            tem = tem + so + " "
            tach(n - arr[i], m - 1, tem, arr, i - 1)

def tim():
    n = int(input("Nhap n: "))
    m = int(input("Nhap m: "))

    arr = array.array('i', [])

    for i in range(2, n):
        if SNT(i) == True: arr.append(i)
    
    kq = " "

    tach(n, m, kq, arr, len(arr) - 1)


tim()

