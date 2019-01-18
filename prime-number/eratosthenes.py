def eratosthenes(n):
    if n < 2: return None
    data = list(range(2, n+1))
    for d in data:
        data = [x for x in data if x == d or x % d != 0]
    return data

def main():
    n = int(input())
    print(eratosthenes(n))

main()