import re

def is_valid_credit_card(card_number):
    # Check if the card number starts with a 4, 5, or 6
    if not re.match(r'^[456]\d{15}$', card_number):
        return False

    # Check if the card number contains exactly 16 digits
    if len(card_number) != 16:
        return False

    # Check if the card number consists only of digits
    if not re.match(r'^\d+$', card_number):
        return False

    # Check if the card number has 4 or more consecutive repeated digits
    if re.search(r'(\d)\1{3,}', card_number):
        return False

    # Check if the card number has any separators other than '-'
    if re.search(r'[^-]\d+-', card_number) or re.search(r'-\d+[^-]', card_number):
        return False

    # Check if the card number has groups of 4 digits separated by '-'
    if re.search(r'^\d{4}-\d{4}-\d{4}-\d{4}$', card_number):
        return True

    # If none of the above conditions are met, the card number is invalid
    return False

T = int(input())
for i in range(T):
    card_number = input()
    if is_valid_credit_card(card_number):
        print("Valid")
    else:
        print("Invalid")
