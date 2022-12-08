def part1():
    f = open('input3.txt', 'r')
    sum = 0
    for line in f.readlines():
        line = line.strip()
        tam = len(line)//2
        comp1 = line[:tam]
        comp2 = line[tam:]
        for letter in comp1:
            if letter in comp2:
                letter = ord(letter)
                sum += letter-96 if letter in range(ord('a'), ord('z')+1) else letter-38
                break
    f.close()
    print(sum)
    
def part2():
    f = open('input3.txt', 'r')
    groups = []
    sum = 0
    for line in f.readlines():
        groups.append(line)
        if len(groups) == 3:
            for letter in groups[0]:
                if letter in groups[1] and letter in groups[2]:
                   letter = ord(letter)
                   sum += letter-96 if letter in range(ord('a'), ord('z')+1) else letter-38
                   break
            groups = []
    print(sum)
    f.close()

def main():
    part1()
    part2()
    
if __name__ == '__main__':
    main()