#!/usr/bin/python3
""" Check if given list of list can open all boxes """


def canUnlockAll(boxes):
    """ Method to check if list contain right secuence to open all boxes """
    cajas = []
    abiertas = [0]

    if not boxes or not isinstance(boxes, list):
        return False

    for h in boxes:
        cajas.append(1)

    cajas[0] = 0

    if abrircaja(boxes[0], boxes, cajas, abiertas):
        return True
    return False


def abrircaja(p, boxes, cajas, abiertas):
    """ Recursive check for opened boxes """
    nuevas = p

    for s in nuevas:
        if s < len(boxes):
            cajas[s] = 0
            if s not in abiertas:
                abiertas.append(s)
                abrircaja(boxes[s], boxes, cajas, abiertas)

    if sum(cajas) == 0:
        return True
    return False