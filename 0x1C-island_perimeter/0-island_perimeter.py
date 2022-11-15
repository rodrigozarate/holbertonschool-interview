#!/usr/bin/python3
""" 0x1C Island Perimeter """


def island_perimeter(grid):
    """ ceros are water, ones are land, land is squared, no lakes """
    perimeter = 0
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if grid[y][x]:
                if x == 0 or not grid[y][x - 1]:
                    perimeter += 1
                if x == len(grid[0]) - 1 or not grid[y][x + 1]:
                    perimeter += 1
                if y == 0 or not grid[y - 1][x]:
                    perimeter += 1
                if y == len(grid) - 1 or not grid[y + 1][x]:
                    perimeter += 1
    return perimeter
