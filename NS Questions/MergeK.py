def merge_two_arrays(arr1, arr2):
    merged = []
    i, j = 0, 0

    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            merged.append(arr1[i])
            i += 1
        else:
            merged.append(arr2[j])
            j += 1

    # Append the remaining elements from both arrays
    merged.extend(arr1[i:])
    merged.extend(arr2[j:])
    
    return merged

def merge_k_sorted_arrays(test_cases):
    result = []

    for _ in range(test_cases):
        K = int(input())
        arrays = [list(map(int, input().split())) for _ in range(K)]
        
        # Merge each array with the result iteratively
        for i in range(1, K):
            arrays[0] = merge_two_arrays(arrays[0], arrays[i])

        result.append(arrays[0])

    return result

# Example usage
T = int(input())
merged_arrays = merge_k_sorted_arrays(T)

# Print the merged arrays
for merged_array in merged_arrays:
    print(" ".join(map(str, merged_array)))
