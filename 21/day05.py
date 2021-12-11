from operator import methodcaller

f = open("day5.txt", "r")

matrix = {(i,j) : 0 for i in range(1000) for j in range(1000)}
lines = []
for line in f:
    line = list(list(map(int, tupla)) for tupla in map(methodcaller("split", ","), map(str.strip, line[:-1].split("->"))))
    x1 = line[0][0]
    x2 = line[1][0]
    y1 = line[0][1]
    y2 = line[1][1]
    if x1 == x2:
        l = [(x1, j) for j in range(min(y1, y2), max(y1,y2)+1)]
    elif y1 == y2: 
        l = [(i, y1) for i in range(min(x1, x2), max(x1,x2)+1)]
    else:
        if (x1 > x2 and y2 > y1) or (x2 > x1 and y1 > y2):
            l = [(i, j) for i, j in zip(range(min(x1, x2), max(x1,x2)+1), range(max(y1, y2), min(y1,y2)-1, -1))]
        else:
            l = [(i, j) for i, j in zip(range(min(x1, x2), max(x1,x2)+1), range(min(y1, y2), max(y1,y2)+1))]

    for tupla in l:
        matrix[tupla] += 1

    lines.append(line)

soma = sum(1 for i in matrix.values() if i >= 2)
print(soma)
