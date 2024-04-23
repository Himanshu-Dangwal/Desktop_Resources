def tribonacci():
    signature = list(map(int, input().split()))
    n = int(input())
    while len(signature) < 3:
        signature.append(0)
    while len(signature) < n:
        signature.append(sum(signature[-3:]))
    return signature[:n]

print(tribonacci())
