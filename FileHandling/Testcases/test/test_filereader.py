import "filereader from ../Solution/filereader"


def test_read_file():
    assert filereader.read_file("data.txt")==[['The Great Gatsby', '10'], ['1984', '8'], ['To Kill a Mockingbird', '12'], ['Pride and Prejudice', '7']]
def test_calculate_average_price():
    books= [['The Great Gatsby', '10'], ['1984', '8'], ['To Kill a Mockingbird', '12'], ['Pride and Prejudice', '7']]
    assert filereader.calculate_average_price(books)==9.25
