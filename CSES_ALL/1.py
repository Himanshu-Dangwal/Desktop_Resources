s = input().strip()

n = len(s)
prefix_sum = [0] * (n + 1)

for i in range(n):
    prefix_sum[i + 1] = prefix_sum[i] + int(s[i])

max_len = 0

for length in range(2, n + 1, 2):
    for i in range(n - length + 1):
        mid = i + length // 2
        left_sum = prefix_sum[mid] - prefix_sum[i]
        right_sum = prefix_sum[i + length] - prefix_sum[mid]

        if left_sum == right_sum:
            max_len = max(max_len, length)

print(max_len)
