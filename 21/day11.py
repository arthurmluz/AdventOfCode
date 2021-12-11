from termcolor import colored
import time

f = open("day11.txt", "r")

matrix = []
for line in f:
    matrix_line = [int(num) for num in line[:-1]]
    matrix.append(matrix_line)

# decepcionado com essa função.
def neighbors(lin, col):

    if lin > 0: # posso olhar pra cima 
        matrix[lin-1][col]+=1

        if matrix[lin-1][col] >= 9 and (lin-1, col) not in exploded:
            exploded.append((lin-1, col))

        if col > 0: # tenho diagonal na esquerda em cima
            matrix[lin-1][col-1]+=1

            if matrix[lin-1][col-1] >= 9 and (lin-1, col-1) not in exploded:
                exploded.append((lin-1, col-1))


        if col < len(matrix_line)-1: # diagonal na direita em cima
            matrix[lin-1][col+1]+=1

            if matrix[lin-1][col+1] >= 9 and (lin-1, col+1) not in exploded:
                exploded.append((lin-1, col+1))


    if lin < len(matrix)-1: # posso olhar pra baixo
        matrix[lin+1][col]+=1

        if matrix[lin+1][col] >= 9 and (lin+1, col) not in exploded:
            exploded.append((lin+1, col))

        if col > 0: # tenho diagonal na esquerda embaixo
            matrix[lin+1][col-1]+=1

            if matrix[lin+1][col-1] >= 9 and (lin+1, col-1) not in exploded:
                exploded.append((lin+1, col-1))

        if col < len(matrix_line)-1: # diagonal na direita embaixo
            matrix[lin+1][col+1]+=1

            if matrix[lin+1][col+1] >= 9 and (lin+1, col+1) not in exploded:
                exploded.append((lin+1, col+1))

    if col > 0: # posso olhar pra esquerda
        matrix[lin][col-1]+=1

        if matrix[lin][col-1] >= 9 and (lin, col-1) not in exploded:
            exploded.append((lin, col-1))

    if col < len(matrix_line)-1:
        matrix[lin][col+1]+=1

        if matrix[lin][col+1] >= 9 and (lin, col+1) not in exploded:
            exploded.append((lin, col+1))


def imprime(steps):
    print('\033[2J\033[H', end="")
    print("------ step", steps, " -------")
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] >= 9:
                print(colored(str('▓'), 'red'), end="")
            else:
                print(colored(str('▓'), 'white'), end="")
        print("")
    time.sleep(0.1)

part1 = 0
steps = 0
imprime(steps)

while( steps < 1000 ):
    exploded = []
    for lin in range(len(matrix)):
        for col in range(len(matrix_line)):
            matrix[lin][col]+=1
            if matrix[lin][col] >= 9:
                exploded.append((lin,col)) 

    steps +=1
    imprime(steps)

    for tupla in exploded:
        neighbors(tupla[0], tupla[1])

    if len(exploded) == len(matrix)*len(matrix_line):
        part2 = steps+1
        imprime(steps)
        break

    for tupla in exploded:
        if steps < 100: 
            part1 +=1
        matrix[tupla[0]][tupla[1]] = -1 


print(part1)
print(part2)
