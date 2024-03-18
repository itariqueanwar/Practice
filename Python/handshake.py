#!/bin/python3

import os

def handshake(n):
    # Calculate the number of handshakes using the formula: n * (n-1) / 2
    return n * (n - 1) // 2

if __name__ == '_main_':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for _ in range(t):
        n = int(input().strip())

        result = handshake(n)

        fptr.write(str(result) + '\n')

    fptr.close()