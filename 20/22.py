#deck1 = [9, 2, 6, 3, 1];
#deck2 = [5, 8, 4, 7, 10];
deck1 = [13,25,18,6,42,8,37,27,44,38,10,28,50,5,16,47,30,29,39,21,2,4,12,35,32]
deck2 = [20,14,46,34,7,26,15,43,36,49,11,23,31,48,1,19,45,22,24,40,41,17,33,9,3]

jogo = 1

def joga(d1, d2):
  global jogo
  rodada = 0
  rounds = []
  while len(d1) and len(d2) :
    rodada += 1


    if (d1[:], d2[:]) in rounds:
      return 1 # o player 1 ganhou.

    rounds.append((d1[:], d2[:]))
  
    top1 = d1.pop(0)
    top2 = d2.pop(0)

    if len(d1) >= top1 and len(d2) >= top2:
      r = rodada
      jogo += 1
      winner = joga( d1[:top1], d2[:top2] )
      jogo -= 1
      rodada = r
    else:
      winner = (top1 < top2) + 1

    if winner == 1:
      d1.append(top1)
      d1.append(top2)
    else:
      d2.append(top2)
      d2.append(top1)

  winner = 1
  if len (deck2): winner = 2
  
  return winner

ret = joga(deck1, deck2)

winner = deck1
if ret == 2:
  winner = deck2

resposta = 0
tamanho = len(winner)
for i in range( tamanho ):
  resposta += winner[ i ] * (tamanho - i)

print(resposta)