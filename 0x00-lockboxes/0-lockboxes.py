#!/usr/bin/python3
""" Check if given list of list can open all boxes """


def canUnlockAll(boxes):
    """ Method to check if list contain right sequence to open all boxes """
    abiertas = [0]

    if not boxes or not isinstance(boxes, list):
        return False

    for h, k in enumerate(boxes):
        for x in boxes[h]:
            if x not in abiertas and x < len(boxes):
                abiertas.append(x)

    if len(abiertas) == len(boxes):
        return True
    return False
