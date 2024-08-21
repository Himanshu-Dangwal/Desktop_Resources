# def funcA(n):
#     if n == 0:
#         return
#     else:
#         print(n, end=' ')
#         funcB(n-1)

# def funcB(n):
#     if n == 1 or n == 0:
#         print(n, end=' ')
#         return
#     else:
#         print(n, end=' ')
#         funcA(n//2)

# funcA(10)

x = input()
print(x*3)

y = list(map(int, input().split()))
print(y)