from termcolor import colored
from random import randint
import time


f = open("day9.txt", "r")

matriz = []
for line in f:
    matriz.append(list(map(int, [x for x in line[:-1]])))


part1 = 0


low_points = []
for j in range(len(matriz)):
    for i in range(len(line)-1):

        if j+1 < len(matriz): # posso olhar para a direita
            if matriz[j][i] >= matriz[j+1][i]:
                continue

        if i+1 < len(line)-1: # posso olhar pra baixo
            if matriz[j][i] >= matriz[j][i+1]:
                continue

        if j > 0: # posso olhar pra esquerda
             if matriz[j][i] >= matriz[j-1][i]:
                continue
   
        if i > 0: # posso olhar pra cima
             if matriz[j][i] >= matriz[j][i-1]:
                continue

        part1 += matriz[j][i] + 1
        low_points.append((j,i))

print(part1)

def imprime(basins_toPrint):
    print('\033[2J\033[H', end="")
    for j in range(int(len(matriz)/2)):
        for i in range(int((len(line)-1))):
            if (j,i) in basins_toPrint:
                random = basins_toPrint[(j,i)]
                if random == 0:
                    print(colored(str('▓'), 'red'), end="")
                elif random == 1:
                    print(colored(str('▓'), 'cyan'), end="")
                elif random == 2:
                    print(colored(str('▓'), 'yellow'), end="")
                elif random == 3:
                    print(colored(str('▓'), 'blue'), end="")
                elif random == 4:
                    print(colored(str('▓'), 'green'), end="")
                else:
                    print(colored(str('▓'), 'magenta'), end="")
            else:
                print(colored(str('▓'), 'white'), end="")
        print("")
    time.sleep(0.09)


                

def bfs(low_point, basins, basins_toPrint, random):
    global part2

    lista = [low_point]
    basin = [low_point]
    while(lista):
        j, i = lista.pop(0)

        if j+1 < len(matriz) and (j+1,i) not in basin and matriz[j+1][i] != 9: # posso olhar pra direita
            lista.append((j+1,i))
            basin.append((j+1,i))

        if i+1 < len(line)-1 and (j,i+1) not in basin and matriz[j][i+1] != 9 : # posso olhar pra baixo
            lista.append((j,i+1))
            basin.append((j,i+1))

        if j > 0 and (j-1,i) not in basin and matriz[j-1][i] != 9 : # posso olhar pra esquerda
            lista.append((j-1,i))
            basin.append((j-1,i))

        if i > 0 and (j,i-1) not in basin and matriz[j][i-1] != 9 : # posso olhar pra cima
            lista.append((j,i-1))
            basin.append((j,i-1))

        basins_toPrint[(j, i)] = random
        if j <= int(len(matriz)/2) and i <= (len(line)-1):
            imprime(basins_toPrint)

    basins.append(basin)

basins_toPrint = {}
basins = []
for idx, i in enumerate(low_points):
        bfs(i, basins, basins_toPrint, randint(0,6))


a = sorted(list(map(len, basins)), reverse=True)
part2 = a[0] * a[1] * a[2] 
print(part2)



