import sys, copy
from heapq import heappop, heappush

f = open(sys.argv[1], 'r')
matrix = {(numLines, numColumns): value for numLines, line in enumerate(f) for numColumns, value in enumerate(list(map(int, line[:-1])))}
last = list(matrix)[-1]

matrix2 = copy.deepcopy(matrix) 
def generateMatrix(minLine, minColumn, maxLine, maxColumn):
    for lines in range(minLine, maxLine):
        for columns in range(minColumn, maxColumn):
            value = matrix2[(lines-minLine, columns-minColumn)]+1
            matrix2[(lines,columns)] = value if value <= 9 else 1 

generateMatrix(0, last[1]+1, last[1]+1, (last[1]+1)*5)
generateMatrix(last[0]+1, 0, (last[0]+1)*5, (last[1]+1)*5)

def dijkstra(grafo):
    dist = {}
    lista = []
    for v in grafo:
        dist[v] = sys.maxsize
        heappush(lista, (dist[v], v))

    dist[(0,0)] = 0
    while(len(lista)):
        u = heappop(lista)[1]
        for i in range(-1, 2):
            for j in range(-1, 2):
                if j != 0 and i != 0:
                    continue
                nodo = (u[0]+i, u[1]+j) 
                if nodo in grafo:
                    aux = dist[u] + grafo[nodo]
                    if aux < dist[nodo]:
                        dist[nodo] = aux

    return dist

dist = dijkstra(matrix)
print('part1: ', dist[last])

last = list(matrix2)[-1]
dist = dijkstra(matrix2)
print('part2: ', dist[last])
