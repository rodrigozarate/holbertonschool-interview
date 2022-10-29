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

    for coin_val in coins:
        while total >= coin_val:
            total -= coin_val
            coin_sum += 1

    if coin_sum == 0 or total != 0:
        return -1

    return coin_sum
