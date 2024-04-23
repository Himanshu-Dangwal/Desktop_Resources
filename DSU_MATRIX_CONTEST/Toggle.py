def toggle_case(s):
    result = ""
    for c in s:
        if c.isalpha():
            if c.islower():
                result += c.upper()
            else:
                result += c.lower()
        else:
            result += c
    return result

s = input()
result = toggle_case(s)
print(result)
