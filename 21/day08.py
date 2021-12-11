from operator import methodcaller

f = open("day8.txt", "r")

part1 = part2 = 0
for line in f:
    output_values = list(map(methodcaller("split", " ") ,map(str.strip, line[:-1].split("|"))))

    for idx, x in enumerate(map(len, output_values[0])):
        if x == 2:
            um = output_values[0][idx]
        if x == 4:
            quatro = output_values[0][idx]

    quatro = [i for i in quatro if i not in um] # removes segments that light up 1 from 4
    um = [um[0], um[1]]

    lista = [0,0,0,0]
    for idx, x in enumerate(map(len, output_values[1])):
        part1 += 1 if x == 2 or x == 4 or x == 3 or x == 7 else 0
        segmentos = output_values[1][idx]
        if x == 2:
            lista[idx] = 1
        elif x == 4:
            lista[idx] = 4
        elif x == 3:
            lista[idx] = 7
        elif x == 7:
            lista[idx] = 8
        else:
            # numero é 3 ou 9 ou 0
            if um[0] in segmentos and um[1] in segmentos:
                if x == 6:
                    lista[idx] = 0 if quatro[0] not in segmentos or quatro[1] not in segmentos else 9
                else:
                    lista[idx] = 3
            # numero é 5 ou 6
            elif quatro[0] in segmentos and quatro[1] in segmentos:
                lista[idx] = 5 if x == 5 else 6
            # numero é 2 ou 0
            else:
                lista[idx] = 2 if x == 5 else 0
    
    part2 += int(",".join([str(num) for num in lista]).replace(",", ""))

print(part1)
print(part2)
