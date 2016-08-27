def fib(n):
    if n == 0:
        return 1
    if n == 1:
        return 1
    return fib(n-1) + fib(n-2)

def fibExtreme(n, computed = {0: 0, 1: 1}):
    if n not in computed:
        computed[n] = fibExtreme(n-1, computed) + fibExtreme(n-2, computed)
    return computed[n]

nums = 0
for i in range(10):
    fi = fibExtreme(i)
    if fi % 2 == 0:
        nums += fi
print(nums)
