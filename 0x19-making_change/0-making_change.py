#!/usr/bin/python3
"""
Change coin simulation
@author: Rodrigo Zárate Algecira
"""


def makeChange(coins, total):
    """ coins list  of coins, total value to get """
    if total <= 0:
        return 0

    coins.sort(reverse=True)

    coin_sum = 0
    left = total
    for coin_val in coins:
        if coin_val <= left:
            cant = left // coin_val
            coin_sum += cant
            left -= cant * coin_val
        if left == 0:
            break

    if coin_sum == 0 or left != 0:
        return -1

    return coin_sum
