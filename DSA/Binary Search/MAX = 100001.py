MAX = 100001
phi = [0] * MAX
result = [0] * MAX

def compute_totient():
    phi[1] = 1
    for i in range(2, MAX):
        if phi[i] == 0:
            phi[i] = i - 1
            for j in range(i << 1, MAX, i):
                if phi[j] == 0:
                    phi[j] = j
                phi[j] = (phi[j] // i) * (i - 1)

def sum_of_gcd(num):
    compute_totient()
    for i in range(1, MAX):
        for j in range(2, MAX // (i*j) ,1):
            result[i * j] += i * phi[j]
    
    for i in range(2, MAX):
        result[i] += result[i - 1]

    return result[num]

if __name__ == "__main__":
    N = int(input())
    print(sum_of_gcd(N))
