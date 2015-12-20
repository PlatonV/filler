#!/usr/bin/python3

from random import *

f = open('shapes', 'r')
g = open('generated.txt', 'w')

n = int(input('Enter n:'))

shapes = []
for line in f:
    shapes.append(line)


for i in range(n):
    mat = [['.' for e in range(4)] for e in range(4)]
    shape = shapes[randint(0, len(shapes) - 1)]
    i = 1
    j = 1
    mat[i][j] = '#'
    for c in shape:
        if c == 'r':
            j += 1
        elif c == 'd':
            i += 1
        elif c == 'l':
            j -= 1
        elif c == 'u':
            i -= 1
        mat[i][j] = '#'
    for q in range(4):
        for p in range(4):
            g.write(str(mat[q][p]))
        g.write('\n')
    g.write('\n')

g.close()
f = open('generated.txt', 'r')
for line in f:
    print(line, end='')
