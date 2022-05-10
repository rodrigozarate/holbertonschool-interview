#!/usr/bin/python3
""" Module to calcule min number of operations """


def minOperations(n):
    """ min number of ops """
    ops = 0
    step = 1
    value = 0

    while step < n:
        if n % step == 0:
            value = step
            ops += 1
            step *= 2
        else:
            step += value
        ops += 1

    return ops
