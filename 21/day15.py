import sys, copy
from heapq import heappop, heappush
from termcolor import colored

f = open(sys.argv[1], 'r')

matrix = {(numLines, numColumns): value for numLines, line in enumerate(f) for numColumns, value in enumerate(list(map(int, line[:-1])))}
last = list(matrix)[-1]

def imprime():
    for i in range(last2[0]+1):
        for j in range(last2[1]+1):
            if i < last[0]+1 and j < last[1]+1:
                print(colored(str(matrix2[(i,j)]), 'red'), end = "")
            else:
                print(matrix2[(i,j)], end="")
        print("")

matrix2 = copy.deepcopy(matrix)
for lines in range(0, (last[0]+1)):
    for columns in range(last[1]+1, (last[1]+1)*5):
        value = matrix2[(lines,columns-(last[1]+1))]+1
        matrix2[(lines,columns)] = value if value <= 9 else 1 

for lines in range(last[0]+1, (last[0]+1)*5):
    for columns in range(0, (last[1]+1)*5):
        value = matrix2[(lines-(last[0]+1),columns)]+1
        matrix2[(lines,columns)] = value if value <= 9 else 1 


last2 = list(matrix2)[-1]

def retiraMin(lista, dist):
    menor = sys.maxsize
    menorNodo = None
    for i in lista:
        if dist[i] <= menor:
            menorNodo = i
            menor = dist[i]
    return menorNodo

def dijkstra(grafo):
    dist,prev = {}, {}
    lista = []
    for v in grafo:
        dist[v] = sys.maxsize
#        lista.append(v)
        heappush(lista, (dist[v], v))

    dist[(0,0)] = 0
    while(len(lista)):
#        u = retiraMin(lista, dist)
#        lista.remove(u)
        u = heappop(lista)[1]
        for i in range(-1, 2):
            nodo = (u[0]+i, u[1]) 
            if nodo in grafo:
                aux = dist[u] + grafo[nodo]
                if aux < dist[nodo]:
                    dist[nodo] = aux

        for j in range(-1, 2):
            nodo = (u[0], u[1]+j) 
            if nodo in grafo:
                aux = dist[u] + grafo[nodo]
                if aux < dist[nodo]:
                    dist[nodo] = aux

    return dist

dist = dijkstra(matrix)
print('part1: ', dist[last])
dist = dijkstra(matrix2)
print('part2: ', dist[last2])
