import sys

f = open(sys.argv[1], "r")
RANGEX = 1312
RANGEY = 900

matrix = {}
fold = []
for line in f:
    if len(line) == 1:
        continue
    if line[0:4] == 'fold':
        fold.append(line[11:-1].split('='))
        continue
    i,j = map(int, line[:-1].split(","))
    matrix[(j,i)] = 1

def imprime():
    for i in range(RANGEY):
        for j in range(RANGEX):
            if (i,j) in matrix:
                print('#', end='')
            else:
                print(' ', end='')
        print("")

part1 = 0
while(len(fold)):
    instruc, axis = fold.pop(0)
    new_matrix = {}
    for dot in matrix:
        y, x = dot

        if instruc == 'y' and y > int(axis):
            RANGEY = int(axis)
            y = abs(y - (2*int(axis)))
        elif instruc == 'x' and x > int(axis):
            RANGEX = int(axis)
            x = abs(x - (2*int(axis)))

        new_matrix[(y,x)] = 0
    
    matrix = new_matrix
    if part1 == 0:
        part1 = len(new_matrix)

print(part1)
imprime()
