from math import gcd
from functools import reduce
import collections

def hasGroupsSizeX(deck):
    vals = collections.Counter(deck).values()
    return reduce(gcd, vals) >= 2

if __name__ == "__main__":
    n = int(input())
    deck = list(map(int, input().split()))
    if(hasGroupsSizeX(deck)):
        print("true")
    else:
        print("false")
