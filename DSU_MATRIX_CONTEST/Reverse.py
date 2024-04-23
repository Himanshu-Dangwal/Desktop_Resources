def reverse_words(s):
    words = s.split()
    reversed_words = [''.join(reversed(word)) for word in words]
    return ' '.join(reversed_words)

s = input()
result = reverse_words(s)
print(result)
