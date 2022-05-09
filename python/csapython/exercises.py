"""
R-1.1: Write a short Python function is_multiple(n,m) that takes two integer values 
and returns True if n is a multple of m, that is n = mi for some integer i and
false otherwise
"""
def is_multiple(n, m):
    return True if n % m == 0 else False

"""
R-1.2: is_even(k), takes an integer and returns True if k is even and False otherwise.
Cannot use multiplication, modulu or division operators.
"""
def is_even(k):
    pass

"""
R-1.3: minmax(data) takes sequence of one or more numbers and returns smallest and largest.
"""
def minmax(data):
    min = int()
    max = int()
    for val in data:
        if val >= max:
            max = val
        if val <= min:
            min = val
    return (min, max)

"""
R-1.4: Write function that takes positive integer n and returns the sum of the squares of all positive integers smaller than n.
"""
def sum_squares_less(n):
    sum = 0
    for val in range(n):
       sum += val**2 
    return sum
