#!/usr/bin/python3
""" island_perimeter function Module """


def island_perimeter(grid):
    """ returns the perimeter of island described in grid """
    perimeter = 0

    grid_rows = len(grid)

    if grid != []:
        grid_columns = len(grid[0])

    for x in range(grid_rows):
        for b in range(grid_columns):
            if grid[x][b] == 1:
                if (x - 1) == -1 or grid[x - 1][b] == 0:
                    perimeter += 1
                if (x + 1) == grid_rows or grid[x + 1][b] == 0:
                    perimeter += 1
                if (b - 1) == -1 or grid[x][b - 1] == 0:
                    perimeter += 1
                if (b + 1) == grid_columns or grid[x][b + 1] == 0:
                    perimeter += 1

    return perimeter
