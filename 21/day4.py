chosen = []
numeros = {}
matrizes = []

f = open("exinput.txt", "r")

matrizAtual = []
linhaAtual = []

inputLines = linhas = matriz = 0

for line in f:
    inputLines+=1
    if inputLines == 1:
        chosen = list(map(int, line[:-1].split(",")))
        inputLines+=1
        continue
    
    linha = line[:-1].split()
    if linha:
        for idx, num in enumerate(linha):
            linhaAtual.append({int(num): 0})
            if int(num) in numeros:
                numeros[int(num)].append((matriz,linhas,idx))
            else:
                numeros[int(num)] = [(matriz,linhas, idx)] 

        linhas+=1

    else:
        if matrizAtual:
            matrizes.append(matrizAtual)
            matrizAtual = []
            linhas = 0
            matriz+=1
        continue

    matrizAtual.append(linhaAtual)
    linhaAtual = []

bingo = False
for num in chosen:
    for i in range(len(numeros[num])):
        values = numeros[num][i]
        z = values[0] # which matrix
        x = values[1] # which line
        y = values[2] # which column
        matrizes[z][x][y][num] = 1

        pontosLinha = sum(list(value.values())[0] for value in matrizes[z][x])

#        if(pontosLinha == 5):
#            bingo = True
#            print("BINGOOO: ", matrizes[z][x])

        pontosColuna = 0 
        for lin in range(5):
            pontosColuna += list(matrizes[z][lin][y].values())[0]
        
        if pontosColuna == 5 or pontosLinha == 5:
#            for value in matrizes[z]:
#                print(value)
#            for i in range(5):
#                for j in range(5):
#                    print(list(matrizes[z][i][j].values())[0])
#                    if matrizes[z][i][j]:

            soma = 0
            for line in matrizes[z]:
                for dic in line:
                    valor = list(dic.values())[0]
                    if valor == 0:
                        soma += list(dic.keys())[0]
            print("soma = ", soma, " num = ", num, " total = ", soma*num )
            print("part 1 = ", sum(map(sum, ((value.values())[0] for value in matrizes[z]))))
            print(matrizes)
            exit()
