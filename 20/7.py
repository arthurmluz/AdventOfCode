
lines = [line.rstrip() for line in open('7.txt').readlines()]

Bro = { }
Cor = { }

for l in lines:
  words = l.split(" ");
  cor = words[0] + " " + words[1]
  fld = 4
  
  while fld < len( words ) :
    outra = words[fld+1] + " " + words[fld+2]
    Cor[ cor ] = Cor[ outra ] = 1
    if outra != "other bags." :
      Bro[ ( cor, outra ) ] = words[fld]
    fld += 4

javi = set()
def explora( cor ) :
  for c1 in Cor :
    if ( c1, cor ) in Bro :
      if c1 not in javi:
        print(c1)
        javi.add(c1)
        explora( c1 )

def reexplora(cor):
  res = 1
  for outra_cor in Cor:
    if (cor, outra_cor) in Bro:
      res += int( Bro[(cor, outra_cor)] ) * reexplora(outra_cor)
  return res

explora( "shiny gold" )
print(len(javi))
part2 = reexplora( "shiny gold" )
print(part2 - 1)

