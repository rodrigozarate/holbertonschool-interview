#!/usr/bin/python3
""" Validate unicode data set """


def validUTF8(data):
    """ Validate UTF-8 encoding """
    if not (type(data) is list and all([isinstance(n, int) for n in data])):
        return False

    data = [n + 256 if n < 0 and n > -129 else n for n in data]

    print(data)
    print('-----------')

    data = [n & 0xFF if n >= 0 else n for n in data]

    print(data)
    print('-----------')
    try:
        bytes(data).decode(encoding='utf-8', errors='strict')
    except (ValueError, UnicodeDecodeError):
        return False

    return True
