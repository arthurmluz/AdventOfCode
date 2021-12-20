import sys, json, math
def trees(item):
    if isinstance(item['left'], list):
        tree = {'nivel': item['nivel']+1, 'left': item['left'][0], 'right': item['left'][1], 'father': item}
        item['left'] = tree
        trees(tree)

    if isinstance(item['right'], list):
        tree = {'nivel': item['nivel']+1, 'left': item['right'][0], 'right': item['right'][1], 'father': item}
        item['right'] = tree
        trees(tree)

def findRightValueOnLeft(item, value):
    if isinstance( item['right'], int ):
        print("achei o mais a direita", item['right'], " adicionando ", value)
        item['right'] += value
    else:
        findRightValueOnLeft(item['right'], value)

def findLeft(item, value, direction):
    if isinstance(item['left'], int):
        item['left'] += value
    else:
        if 'father' in item:
            direction = 'right' if item['father']['right'] == item else 'left'
            findLeft(item['father'], value, direction)
        else:
            if direction == 'right':
                findRightValueOnLeft( item['left'], value )


def findLeftValueOnRight(item, value):
    if isinstance( item['left'], int ):
        print("achei o mais a esquerda", item['left'], " adicionando ", value)
        item['left'] += value
    else:
        findLeftValueOnRight(item['left'], value)


def findRight(item, value, direction):
    if isinstance(item['right'], int):
        item['right'] += value
    else:
        if 'father' in item:
            direction = 'right' if item['father']['right'] == item else 'left'
            findRight(item['father'], value, direction)
        else:
            if direction == 'left':
                findLeftValueOnRight( item['right'], value )

def explodes(item):
    father = item['father']
    if isinstance(father['left'], dict) and father['left']['nivel'] == 4:
        findLeft ( father, father['left']['left'],  'left' )
        findRight( father, father['left']['right'], 'left' )
        father['left'] = 0
        return 1

    if isinstance(father['right'], dict) and father['right']['nivel'] == 4:
        findLeft ( father, father['right']['left'],  'right' )
        findRight( father, father['right']['right'], 'right' )
        father['right'] = 0
        return 1
    return 0

def splits(item, direction):
    if direction == 'left':
        splited = item['left']
        item['left'] = {'nivel': item['nivel']+1, 'left': math.floor(splited/2), 'right': math.ceil(splited/2), 'father': item}
        return 1 
    else:
        splited = item['right']
        item['right'] = {'nivel': item['nivel']+1, 'left': math.floor(splited/2), 'right': math.ceil(splited/2), 'father': item}
        return 1
    return 0


def findFather(item):
    if 'father' in item:
        return findFather(item['father'])
    else:
        return item

def reduces(item):
    if item['nivel'] == 4:
        print("explodindo: ", item['left'], item['right'])
        if explodes(item):
            reduces(findFather(item))

    if isinstance(item['left'], dict):
        reduces(item['left'])

    elif item['left'] >= 10:
        if splits(item, 'left'):
            reduces(item)

    if isinstance(item['right'], dict):
        reduces(item['right'])

    elif item['right'] >= 10:
        if splits(item, 'right'):
            reduces(item)


def transformToList(res, tree):
    if isinstance(tree['left'], dict):
        res += "["
        res = transformToList(res, tree['left'])
        res += "],"
    else:
        res += str(tree['left'])+","
    if isinstance(tree['right'], dict):
        res += "["
        res = transformToList(res, tree['right'])
        res += "],"
    else:
        res += str(tree['right'])
    return res 

def testing(tree):
    tree = { 'nivel': 0, 'left': res[0], 'right': res[1] }
    trees(tree)
    reduces(tree)
    print(tree)
    string = transformToList("[", tree) + ']'
    # fixes the string
    tmp = ""
    for idx, char in enumerate(string): 
        if string[idx] == ',' and string[idx+1] == ']':
            continue
        else:
            tmp += char
    print(tmp)
    exit()


f = open(sys.argv[1], 'r')

lines = []
for line in f:
    res =  json.loads(line[:-1])
#    testing(res)
    lines.append(res)
    if len(lines) % 2 == 0:
        print(lines[0], "outra:" ,lines[1])
        tree = { 'nivel': 0, 'left': lines[0], 'right': lines[1] }
        trees(tree)
#        print(tree)
        reduces(tree)
        # transforms the tree back in to a string list
        string = transformToList("[", tree) + ']'
        # fixes the string
        tmp = ""
        for idx, char in enumerate(string): 
            if string[idx] == ',' and string[idx+1] == ']':
                continue
            else:
                tmp += char
        # makes it a list again
        lines = [json.loads(tmp)]

print(tmp)

