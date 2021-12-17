import sys
f = sys.argv[1]

binary = bin(int(f, 16))[2:].zfill(len(sys.argv[1])*4)
print(binary)
part1 = 0
def recursive(packet):
    global part1
    version = packet[0:3]
    typeID = packet[3:6]
    part1 += int(version, 2)
    if int(typeID, 2) == 4: #literal value
        packet = packet[6:]
        lista = []
        i = 0
        while (i < len(packet)):
            lista.append(packet[i:i+5])
            i+=5
            if packet[i-5] == '0':
                break
   
        value = int(''.join(list(map(lambda x: x[1:], lista))),2)
        size = 7 + len(lista)*4
        return value, size, packet[i:] 

    else:
        L = packet[6]
        subpacketLen = 11 if L == '1' else 15
        length = int(packet[7:6+subpacketLen+1],2)
        length += 1 if L == '1' else 0
        packet = packet[6+subpacketLen+1:]
        while length-1 > 0:
            print(length)
            print("estou enviando o pacote", packet)
            value, size, subpacket = recursive(packet)
            print('subpacket: ', value, size, subpacket)
            length -= size if L == '0' else 1 
            packet = subpacket
        return 0, size, subpacket

print(recursive(binary))
print(part1)

