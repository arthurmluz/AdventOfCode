chosen = []
numeros = {}
matrizes = []

f = open("day4.txt", "r")

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

jafez = []
for num in chosen:
    for i in range(len(numeros[num])):
        values = numeros[num][i]
        z = values[0] # which matrix
        x = values[1] # which line
        y = values[2] # which column
        matrizes[z][x][y][num] = 1

        pontosLinha = sum(list(value.values())[0] for value in matrizes[z][x])


        pontosColuna = 0 
        for lin in range(5):
            pontosColuna += list(matrizes[z][lin][y].values())[0]
        
        if pontosColuna == 5 or pontosLinha == 5:
            if z in jafez:
                continue
            jafez.append(z)

            if len(jafez) == len(matrizes) or len(jafez) == 1:
                soma = 0
                soma = sum(map(lambda line: sum(k for d in line for k, v in d.items() if v == 0), matrizes[z]))
                print("soma = ", soma, " num = ", num, " total = ", soma*num )



