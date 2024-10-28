# a simple parser for python. use get_number() and get_word() to read
import numpy
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

# numpy and scipy are available for use
import numpy
import scipy

def alice_wins_probability(R1, B1, R2, B2):
    # Initialize DP table
    dp = [[[[0.0 for _ in range(B2 + 1)] for _ in range(R2 + 1)] for _ in range(B1 + 1)] for _ in range(R1 + 1)]
    
    # Base case: If Bob is out of stones, Alice wins
    for aR in range(R1 + 1):
        for aB in range(B1 + 1):
            dp[aR][aB][0][0] = 1.0  # Alice wins if Bob has no stones left

    # Base case: If Alice is out of stones, she loses
    for bR in range(R2 + 1):
        for bB in range(B2 + 1):
            dp[0][0][bR][bB] = 0.0  # Alice loses if she has no stones left

    # Fill the DP table
    for aR in range(R1 + 1):
        for aB in range(B1 + 1):
            for bR in range(R2 + 1):
                for bB in range(B2 + 1):
                    if aR == 0 and aB == 0:
                        continue  # Skip, already handled
                    if bR == 0 and bB == 0:
                        continue  # Skip, already handled
                    
                    # Alice's turn
                    total = 0.0
                    if aR > 0:  # Alice can choose red
                        total += (dp[aR - 1][aB][bR][bB] * (bR / (bR + bB)))  # Bob guesses red and is correct
                        total += (dp[aR][aB][bR - 1][bB] * (1 - (bR / (bR + bB))))  # Bob guesses red and is wrong
                    
                    if aB > 0:  # Alice can choose blue
                        total += (dp[aR][aB - 1][bR][bB] * (bB / (bR + bB)))  # Bob guesses blue and is correct
                        total += (dp[aR][aB][bR][bB - 1] * (1 - (bB / (bR + bB))))  # Bob guesses blue and is wrong
                    
                    dp[aR][aB][bR][bB] = total

    # The answer we want is dp[R1][B1][R2][B2]
    return dp[R1][B1][R2][B2]

# Input reading
import sys
input = sys.stdin.read
R1, B1, R2, B2 = map(int, input().strip().split())

# Calculate probability
result = alice_wins_probability(R1, B1, R2, B2)

# Print result
print(f"{result:.9f}")