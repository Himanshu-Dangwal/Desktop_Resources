def binary_search_alphabets(alphabets, target):
    low, high = 0, len(alphabets) - 1
    # print(alphabets)
    # print(high)
    while low <= high:
        mid = low + (high - low) // 2

        if alphabets[mid] == target:
            return mid
        elif alphabets[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1  # Target not found

# Input the list of alphabets
line = input()
# print(line)
arr = list(line.split())
# arr = list(map(chr, line.split()))

# Input the target alphabet
ch = input()

result = binary_search_alphabets(arr, ch)
print(result)
