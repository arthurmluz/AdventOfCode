with open('15.txt', 'r') as f:
    testdata1 = '0,3,6'
    data = f.readline().strip()

    lastpositions = {int(n): i+1 for i, n in enumerate(data.split(','))}
    lastitem = list(lastpositions)[-1]
    lastpositions.pop(lastitem)

    for turn in range(len(lastpositions) + 2, 30000001):
        if lastitem not in lastpositions:
            newitem = 0
        else:
            newitem = (turn - 1) - lastpositions[lastitem]
        lastpositions[lastitem] = turn - 1
        lastitem = newitem
        if turn == 2020:
            print(f'Part 1: {lastitem}')
    print(f'Part 2: {lastitem}')
