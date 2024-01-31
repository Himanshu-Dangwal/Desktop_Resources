def compute_totient(MAX):
    phi = [0] * MAX
    phi[1] = 1
    for i in range(2, MAX):
        if phi[i] == 0:
            phi[i] = i - 1
            for j in range(i * 2, MAX, i):
                if phi[j] == 0:
                    phi[j] = j
                phi[j] = (phi[j] // i) * (i - 1)
    return phi

def sum_of_gcd(num, MAX):
    phi = compute_totient(MAX)
    result = [0] * MAX

    for i in range(1, MAX):
        j = 2
        while i * j < MAX:
            result[i * j] += i * phi[j]
            j += 1

    for i in range(2, MAX):
        result[i] += result[i - 1]

    return result[num]
MAX = 100001
n = int(input())
print(sum_of_gcd(n, MAX))