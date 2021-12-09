f = open("exinput.txt", "r")

matriz = []
for line in f:
    matriz.append(list(map(int, [x for x in line[:-1]])))

part1 = 0
print(len(line))
for i in range(len(line)):
    for j in range(len(matriz)):

        if i+1 < len(line):
            print("comparando ", i, " e ", i+1)
            if matriz[i][j] > matriz[i+1][j]:
                continue
        if i-1 > 0:
            if matriz[i][j] > matriz[i-1][j]:
                continue
        if j+1 < len(matriz):
            if matriz[i][j] > matriz[i][j+1]:
                continue
        if j-1 > 0:
            if matriz[i][j] > matriz[i][j-1]:
                continue
            

        part1 += matriz[i][j] + 1
        print("sobrou: ", matriz[i][j], "i: ", i, " j: ", j)

print(matriz)
