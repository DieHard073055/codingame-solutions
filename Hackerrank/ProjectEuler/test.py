def add_multiples_of_3n5(n):
        return (sum(range(0, n, 3)) + sum(range(0, n, 5)) - sum(range(0, n, 15)))

def inaan_multiple(n):
    max = 0
    num = 0
    nnum=0
    i =0
    while( max < n ):
        num += max
        i+=1
        max = 3 * i
    max = 0
    i=0
    while( max < n ):
        num+= max
        i+=1
        max = 5 * i
    max = 0
    i=0
    while( max < n ):
        num -= max
        i+=1
        max= 15 * i

    return num
testcase = int(input())

def sci(n):
    return (n * (n+1)) / 2
def sum(n):
    return sci(((n-1)/3)) * 3 + sci(((n-1)/5)) * 5 - sci(((n-1)/15)) * 15
for i in range(testcase):
    n = int(input())
    print('%d' % (sum(n)))


