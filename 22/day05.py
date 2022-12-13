import re
filename = 'input5.txt'

def createStacks():
    qtdStacks = 9
    stacks = [[] for x in range(qtdStacks)]
    f = open(filename, 'r')
    for line in f.readlines():
        line = line.strip('\n').replace('[', ' ').replace(']', ' ')
        if len(line) == 0 or line[1] == '1':
            break 

        box = 1
        for idx, x in enumerate(line):
            if idx == box:
                if x != ' ':
                    stacks[box//4].append(x)
                box+=4
    f.close()
    return stacks


def part1(): 
    stacks = createStacks()
    f = open(filename, 'r')
    instr = False
    for line in f.readlines():
        line = line.strip('\n')
        if not instr:
            if len(line) == 0: instr = True
            continue

        line = re.findall(r'\d+', line)
        qtd = int(line[0])
        fromStack = int(line[1])-1
        toStack = int(line[2])-1
        for i in range(qtd):
            crate = stacks[fromStack].pop(0)
            stacks[toStack].insert(0, crate)
    f.close()
    for i in stacks:
        print(i[0], end = '')
    print()


def part2():
    stacks = createStacks()
    f = open(filename, 'r')
    instr = False
    for line in f.readlines():
        line = line.strip('\n')
        if not instr:
            if len(line) == 0: instr = True
            continue

        line = re.findall(r'\d+', line)
        qtd = int(line[0])
        fromStack = int(line[1])-1
        toStack = int(line[2])-1
        crates = []
        for i in range(qtd):
            crate = stacks[fromStack].pop(0)
            crates.append(crate)
        crates.reverse() 
        for i in crates:
            stacks[toStack].insert(0, i)

    f.close()
    for i in stacks:
        print(i[0], end = '')
    print()


def main():
    part1()
    part2()


if __name__ == '__main__':
    main()