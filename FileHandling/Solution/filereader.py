def read_file(filename):
    with open(filename, 'r') as file:
        return [line.strip().split(', ') for line in file]


def calculate_average_price(books):
    total_price = sum(float(price) for _, price in books)
    return total_price / len(books) if books else 0




