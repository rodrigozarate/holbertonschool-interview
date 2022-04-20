#!/usr/bin/python3
'''Check if given list of list can open all boxes'''


def canUnlockAll(boxes):
    ''' Method to check if list contain right secuence to open all boxes '''
    cajas = []
    abiertas = [0]
    total = 0
    for h in boxes:
        cajas.append(1)

    cajas[0] = 0

    for i in cajas:
        total = total + i

    if abrircaja(boxes[0], boxes, cajas, abiertas, total):
        return True
    return False


def abrircaja(p, boxes, cajas, abiertas, total):
    ''' Recursive check for opened boxes '''
    nuevas = p
    for s in nuevas:
        cajas[s] = 0
        if s < total:
            if s not in abiertas:
                abiertas.append(s)
                abrircaja(boxes[s], boxes, cajas, abiertas, total)

    if sum(cajas) == 0:
        return True
    else:
        return False