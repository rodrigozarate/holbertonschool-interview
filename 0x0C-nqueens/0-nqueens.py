#!/usr/bin/python3

import sys

if len(sys.argv) is not 2:
    print('Usage: nqueens N')
    exit(1)

if not sys.argv[1].isdigit():
    print('N must be a number')
    exit(1)

N = int(sys.argv[1])

if N < 4:
    print('N must be at least 4')
    exit(1)


def queens(N, i, a, b, c, d):
    if i < N:
        for j in range(N):
            if j not in a and i+j not in b and i-j not in c:
                yield from queens(N, i+1, a+[j], b+[i+j], c+[i-j], d+[[i, j]])
    else:
        yield d

for solution in queens(N, 0, [], [], [], []):
    print(solution)
