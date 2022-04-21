#!/usr/bin/python3
""" Check if given list of list can open all boxes """


def canUnlockAll(boxes):
    """ Method to check if list contain right sequence to open all boxes """
    abiertas = [0]

    if not boxes or not isinstance(boxes, list):
        return False

    for h, k in enumerate(boxes):
        print("key", h)
        print("value", k)
        print("asi va en loop 1: ", abiertas)
        if h in abiertas:
            print("is in keys in hand:", h)
        for x in boxes[h]:
            print("rev", x)

            if x not in abiertas and x < len(boxes) and x != h:
                abiertas.append(x)
                print("asi va: ", abiertas)

    print("asi quedo: ", abiertas)

    if len(abiertas) == len(boxes):
        return True
    return False
