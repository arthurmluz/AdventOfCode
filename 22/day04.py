
def main():
    f = open('input4.txt', 'r')
    count = 0
    count2 = 0
    for line in f.readlines():
        line = line.strip().split(',')
        rg1 = [int(l) for l in line[0].split('-')]
        rg2 = [int(l) for l in line[1].split('-')]

        rg1 = range(rg1[0], rg1[1]+1) if rg1[0] < rg1[1] else range(rg1[1], rg1[0]+1)
        rg2 = range(rg2[0], rg2[1]+1) if rg2[0] < rg2[1] else range(rg2[1], rg2[0]+1)
        if set(rg2).issubset(rg1) or set(rg1).issubset(rg2):
            count+=1

        if set(rg1).intersection(set(rg2)) or set(rg1).intersection(set(rg2)):
            count2+=1
    print(count)
    print(count2)
    f.close()


if __name__ == '__main__':
    main()