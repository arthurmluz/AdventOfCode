from operator import methodcaller

f = open("exinput.txt", "r")

matrix = {(i,j) : 0 for i in range(1000) for j in range(1000)}
lines = []
part1 = []
for line in f:
    line = list(list(map(int, tupla)) for tupla in map(methodcaller("split", ","), map(str.strip, line[:-1].split("->"))))
    if line[0][0] == line[1][0] or line[0][1] == line[1][1]:
        part1.append(line)
    lines.append(line)


print(part1)
