import bisect
import sys
input = sys.stdin.read

def calculate_optimal_cost(arr, l, r):
    pairs = []
    while l < r:
        pairs.append(arr[l] + arr[r])
        l += 1
        r -= 1
    if l == r:  # If odd length, add the middle element as its own group
        pairs.append(arr[l])
    return max(pairs)

def solve():
    data = input().split()
    idx = 0
    n, q = int(data[idx]), int(data[idx+1])
    idx += 2
    A = list(map(int, data[idx:idx+n]))
    idx += n
    queries = list(map(int, data[idx:idx+q]))
    
    A.sort()  # Ensure the array is sorted
    result = []
    
    # Precompute all possible subarrays' optimal costs using sliding window
    optimal_costs = []
    for start in range(n):
        for end in range(start, n):
            cost = calculate_optimal_cost(A, start, end)
            optimal_costs.append((cost, start, end))
    
    # Sort optimal costs for efficient query processing
    optimal_costs.sort()
    
    # Answer each query
    for x in queries:
        total_diff_sum = 0
        # Use binary search to find all subarrays with optimal cost <= x
        for cost, l, r in optimal_costs:
            if cost > x:
                break
            total_diff_sum += A[r] - A[l]
        result.append(total_diff_sum)
    
    # Print results for each query
    print("\n".join(map(str, result)))

