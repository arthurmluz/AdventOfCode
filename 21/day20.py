SIZE = 0
MULTSIZE = 1000
mat = {}
newMat = {}

def createMatrix(f):
    global SIZE
    count = 0
    for line in f.readlines():
        line = line.strip()
        for idx, value in enumerate(line):
            if value == '#':
                mat[(count, idx)] = 0
        count+=1
    SIZE = count

def printMat(matr):
    for tupla in matr:
        print(matr[tupla], end='')
        if tupla[1] == (5)-1:
            print()


def getNeighboursBin(tupla: tuple):
    rg = tupla[0]-1, tupla[0]+2
    rg2 = tupla[1]-1, tupla[1]+2
    binNum = ""
    for i in range(rg[0], rg[1]):
        for j in range(rg2[0], rg2[1]):
            if (i,j) in mat:
                binNum += '1'
            else:
                binNum += '0'
    return int(binNum, 2)


def faz(enhancString):
    jaFeitos = []
    for tupla in mat:
        rg = tupla[0]-1, tupla[0]+2
        rg2 = tupla[1]-1, tupla[1]+2
        for i in range(rg[0], rg[1]):
            for j in range(rg2[0], rg2[1]):
                # se ja foi visitado ignora 
                if (i,j) in jaFeitos: continue

                num = getNeighboursBin((i,j))
                if enhancString[num] == '#':
                    newMat[(i,j)] = 0
                jaFeitos.append((i,j))
    print(len(newMat))



def main():
    global mat, newMat
    f = open('day20.txt', 'r')
    enhancString = f.readline().strip()
    f.readline()
    createMatrix(f)
    # para cada # na matriz
    # coloca os 8 vizinhos numa lista pra AFazer
    # Cria uma lista sobre os que JaforamVisitados
    for i in range(2):
        print("count: ", end='')
        faz(enhancString)
        mat = newMat
        newMat = {}



    
    

if __name__ == '__main__':
    main()