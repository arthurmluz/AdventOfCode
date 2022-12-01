def main():
    maior = []
    tmp = 0
    f = open("input1.txt", "r")
    for line in f.readlines():
        line = line.strip()
        if len(line) == 0:
            maior.append(tmp)
            tmp = 0
        else:
            tmp+= int(line)
    print(sum(sorted(maior, reverse=True)[:3]))
        
if __name__ == '__main__':
    main()