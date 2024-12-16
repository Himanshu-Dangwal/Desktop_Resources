n = int(input())
arr = list(map(int, input().split()))

ans = 0

for x in arr:
    if x < 5:
        print("-1")
        exit()

if n == 1:
    print("5")
else:
    ans = sum(arr)
    print(ans)
