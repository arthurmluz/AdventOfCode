def part1():
    f = open('input2.txt', 'r')
    result = 0
    for line in f.readlines():
        line = line.strip().split(' ')
        jogou = ord(line[0]) - 64 
        joguei = ord(line[1]) - 87 # 88 é o X, entao subtrair dá 1, 2, 3
        result += joguei 
        if jogou == joguei:
            result += 3
        elif (jogou == 1 and joguei == 2) or (jogou == 2 and joguei == 3) or (jogou == 3 and joguei == 1):
            result+=6
    print(result)
    f.close()


def part2():
    f = open('input2.txt', 'r')
    result = 0
    for line in f.readlines():
        line = line.strip().split(' ')
        jogou = ord(line[0]) - 64 
        escolha = ord(line[1]) - 87 # 88 é o X, entao subtrair dá 1, 2, 3
        if escolha == 2: # empatar
            result += jogou + 3
        elif escolha == 1: # perder
            if jogou == 1:
                result += 3
            else:
                result += jogou -1
        elif escolha == 3: # ganhar
            if jogou == 3:
                result += 6 + 1
            else:
                result += 6 +jogou+1
    print(result)
    f.close()
            

def main():
    part1()
    part2()
            

if __name__ == '__main__':
    main()