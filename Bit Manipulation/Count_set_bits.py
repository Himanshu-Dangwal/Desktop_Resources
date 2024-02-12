# Function to initialise the lookup table
def initialize():
    global BitsSetTable256
    BitsSetTable256 = [0] * 256

    # To initially generate the table algorithmically
    BitsSetTable256[0] = 0
    for i in range(256):
        BitsSetTable256[i] = (i & 1) + BitsSetTable256[i // 2]

# Function to return the count of set bits in n
def countSetBits(n):
    global BitsSetTable256
    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24])

def main():
    initialize()
    n = int(input())
    ans = 0

    for i in range(1, n + 1):
        ans += countSetBits(i)

    print(ans)

if __name__ == "__main__":
    main()
