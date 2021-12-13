import copy
import sys
f = open(sys.argv[1], "r")
nodos = {}
arestas = {}
start = []

# OBS 1: I manually changed my input to not accept 'start' or 'end' pointing to someone
# OBS 2: you cant have nodes with more than 1 char like 'az' 
for line in f:
    line = line[:-1].split("-")
    nodos[line[0]] = 0
    nodos[line[1]] = 0
    arestas[(line[0], line[1])] = 0
    if line[0] == 'start': 
        start.append(line[1])
    if line[1] == 'start':
        start.append(line[0])

    if line[1] != 'end' and line[0] != 'start':
        arestas[(line[1], line[0])] = 0

print(nodos)
print(arestas)
# for part1 
def DFS(start):
    count = 0
    lista = [(start, start)]
    while( len(lista) ):
        atual, caminho = lista.pop(0)
        for v in nodos:
            if (atual, v) in arestas:
                if not v.isupper() and v in caminho: # small cave
                    continue
                if v == 'end':
                    count+=1
                    continue

                lista.insert(0, (v, caminho+v))
    return count

# for part 2, because I'm lazy now
def DFS2(start):
    count = 0
    lista = [(start, start)]
    while( len(lista) ):
        atual, caminho = lista.pop(0)
        for v in nodos:
            if (atual, v) in arestas:
                if not v.isupper() and v in caminho: # small cave e já visitou 1 vez
                    temRepetido = False
                    for char in caminho: # olhar toda a string do caminho, e ver se tem alguma caverna pequena que já repetiu
                        if caminho.count(char) > 1 and not char.isupper(): # poderia ter usado uma lista? sim, vou? nao
                            temRepetido = True
                    # se não tem ngm repetido nesse caminho, então podemos repetir essa caverninha
                    if not temRepetido:
                        lista.insert(0, (v, caminho+v))
                    continue

                if v == 'end':
                    count+=1
                    continue

                lista.insert(0, (v, caminho+v))
    return count


part1 = part2 = 0
copyNodos = copy.deepcopy(nodos)

for nodo in start:
    part1 += DFS(nodo)
    nodos = copy.deepcopy(copyNodos)
    part2 += DFS2(nodo)
    nodos = copy.deepcopy(copyNodos)

print(part1)
print(part2)
