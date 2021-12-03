lista1 = []
lista2 = []
values = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
lines = 0

f = open("day3.txt", "r")
for line in f:

    line = line.strip()
    lista1.append(line)
    lista2.append(line)
    
    for idx, num in enumerate(line):
        if num == '1':
            values[idx]+=1

    lines+=1

############## part 1 ####################
res = ""
for i in range(len(line)):
    res += "1" if values[i] > lines/2 else "0"

gamma = int(res,2)
epsilon = pow(2, len(line))-1-gamma
print("gamma: ", gamma, "epsilon: ", epsilon, " power consumption: ", gamma * epsilon)

############# part 2 #####################

total2 = total1  = len(lista2)
for col in range(len(line)):
    count1 = countx = count2 = countx2 = 0

    for lin in range(len(lista1)):
        count1 += 1 if lista1[lin][col] == '1' else 0
        countx += 1 if lista1[lin][col] == 'x' else 0
        
        count2  += 1 if lista2[lin][col] == '1' else 0
        countx2 += 1 if lista2[lin][col] == 'x' else 0

    for lin in range(len(lista1)):
        if total1 > 1:
            fewer = '0' if count1 >= (len(lista1)-countx)/2 else '1'
            if lista1[lin][col] == fewer:
               lista1[lin] = "x"*len(line)
               total1-=1

        if total2 > 1:
           fewer = '0' if count2 >= (len(lista2)-countx2)/2 else '1'
           if lista2[lin][col] != fewer and lista2[lin][col] != 'x':
               lista2[lin] = "x"*len(line)
               total2-=1
           

ox, co2 = 0, 0
for i in lista1:
    if i[0] != 'x':
        ox = (int(i, 2))

for i in lista2:
    if i[0] != 'x':
        co2 = (int(i, 2))

print("oxygen rating: ", ox, " CO2 rating: ", co2, " life rating: ", co2 * ox)

        

