def diagonal_binary_search(matrix, target):
    n = len(matrix)
    low, high = 0, n * n - 1

    while low <= high:
        mid = low + (high - low) // 2
        mid_val = matrix[mid // n][mid % n]

        if mid_val == target:
            return True
        elif mid_val < target:
            low = mid + 1
        else:
            high = mid - 1

    return False

if __name__ == "__main__":
    n = int(input())
    
    matrix = []
    for _ in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)

    target = int(input())

    if diagonal_binary_search(matrix, target):
        print("true")
    else:
        print("false")
