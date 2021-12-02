import sys

nodos = {}
arestas = {}
dependencias = {}
resultado = {}

def legrafo(name):
  arq = open(name, "r")
  for line in arq:
    word = line.split("->")
    word[1] = word[1].strip()
    word[0] = word[0].strip()
    nodos[word[0]] = 0   # "a AND b"
    nodos[word[1]] = 0   # c
    dependencias[word[1]] = 1
    arestas[word[0], word[1]] = 0

    op = word[0].split() # (a) (AND) (b)

    if op[0].isdigit():
      nodos[op[0]] = int(op[0])
    elif len(op) != 2:
      nodos[op[0]] = 0


    if len(op) == 2: # NOT a -> c
      nodos[op[1]] = 0
      arestas[(op[1], word[0])] = 0   # a -> NOT a
      dependencias[word[0]] = 1
      
    if len(op) == 3:    
      if op[2].isdigit():
        nodos[op[2]] = int(op[2])
      else:
        nodos[op[2]] = 0
        
      arestas[(op[0], word[0])] = 0
      arestas[(op[2], word[0])] = 0
      dependencias[word[0]] = 2

      
def calcula(nome):
  words = nome.split()

  if len(words) == 1:
    for (u, v) in arestas:
      if v == nome:
        return nodos[u]
    
  elif len(words) == 2:
    return ~nodos[words[1]] + 65536
    
  elif len(words) == 3:
    if words[1] == "AND":
      return nodos[words[0]] & nodos[words[2]]
    elif words[1] == "OR":
      return nodos[words[0]] | nodos[words[2]]
    elif words[1] == "RSHIFT":
      return nodos[words[0]] >> int(words[2])
    elif words[1] == "LSHIFT":
      return nodos[words[0]] << int(words[2])

def connectGates():
  for u in nodos:
    if u not in dependencias:
      for v in nodos:
        if (u, v) in arestas:
          nodos[v] = nodos[u] # 123 -> x
          dependencias[v] -= 1
          
  continua = True

  while continua:
    continua = False
    for u in dependencias:
      if dependencias[u] == 0:
        dependencias[u] = -1
        for v in nodos:
          if ( u, v ) in arestas and dependencias[v] > 0:
            dependencias[v] -= 1
            if dependencias[v] == 0 :
              nodos[v] = calcula(v)
              continua = True


legrafo("day7.txt")

connectGates()

print(nodos["a"])
