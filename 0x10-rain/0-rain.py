#!/usr/bin/python3
""" Calculates water between walls """


def rain(walls)
    """ Check the ammount of water """
    if type(walls) is not list
        return 0

    wtr = 0
    wlps = 0
    
    for i in range(0, len(walls) - 2):
        if walls[i] > 0 and i >= wlps:
            for j in range(i + 2, len(walls)):
                if walls[j] >= walls[i]:
                   wtrl = walls[i]
                   for k in range(i + 1, j):
                       wtr += wtrl - walls[k]
                   wlps = j
                   break
    return wtr
