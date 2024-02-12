def swap_using_xor(n, m):
    n = n ^ m
    m = n ^ m
    n = n ^ m
    return n, m


def main():
    n, m = map(int, input().split())
    n, m = swap_using_xor(n, m)
    print(n, m)

if __name__ == "__main__":
    main()


