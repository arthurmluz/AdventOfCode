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
    if isinstance(item['right'], int):
        item['right'] += value
    else:
        findRightValueOnLeft(item['right'], value)

def findLeft( item, value ):
    if 'father' in item:
        if item['father']['left'] is item:
                findLeft(item['father'], value)
        else:
            if isinstance(item['father']['left'], int):
                item['father']['left'] += value
            else:
                findRightValueOnLeft(item['father']['left'], value)

def findLeftValueOnRight(item, value):
    if isinstance(item['left'], int):
        item['left'] += value
    else:
        findLeftValueOnRight(item['left'], value)

def findRight(item, value):
    if 'father' in item:
        if item['father']['right'] is item:
            findRight(item['father'], value)
        else:
            if isinstance(item['father']['right'], int):
                item['father']['right'] += value
            else:
                findLeftValueOnRight(item['father']['right'], value)

def explodes(item):
    father = item['father']
    if isinstance(father['left'], dict) and father['left']['nivel'] >= 4:
        findLeft ( item, item['left'] )
        findRight( item, item['right'] )
        father['left'] = 0
        return True

    if isinstance(father['right'], dict) and father['right']['nivel'] >= 4:
        findLeft ( item, item['left'] )
        findRight( item, item['right'] )
        father['right'] = 0
        return True
    return False

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

def imprime(item):
    string = transformToList("[", item) + ']'
    # fixes the string
    tmp = ""
    for idx, char in enumerate(string): 
        if string[idx] == ',' and string[idx+1] == ']':
            continue
        else:
            tmp += char
    return tmp

def explode(item):
    if isinstance(item, dict):
        if item['nivel'] >= 4 and explodes(item):
            explode(findFather(item))
        else:
            explode(item['left'])
            explode(item['right'])

def split(item):
    if isinstance(item['left'], dict):
        split(item['left'])

    if isinstance(item['left'], int):
        if item['left'] >= 10:
            splits(item, 'left')
            return reduces(findFather(item))

    if isinstance(item['right'], dict):
        split(item['right'])

    if isinstance(item['right'], int):
        if item['right'] >= 10:
            splits(item, 'right')
            return reduces(findFather(item))

def reduces(item):
    explode(item)
    split(item)

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

f = open(sys.argv[1], 'r')

def magnitude(item):
    if isinstance(item, int):
        return item
    else:
        return 3*magnitude(item['left']) + 2*magnitude(item['right'])

lines = []
all_lines = []

for line in f:
    res =  json.loads(line[:-1])
    lines.append(res)
    all_lines.append(res)
    if len(lines) % 2 == 0:
        tree = { 'nivel': 0, 'left': lines[0], 'right': lines[1] }
        trees(tree)
        reduces(tree)
        lines = [json.loads(imprime(tree))]

print(imprime(tree))
print('part1: ', magnitude(tree))
part2 = 0
for i in range(len(all_lines)):
    for j in range(len(all_lines)):
        if i == j:
            continue
        tree = { 'nivel': 0, 'left': all_lines[i], 'right': all_lines[j] }
        trees(tree)
        reduces(tree)
        tmp = magnitude(tree)
        if tmp > part2:
            part2 = tmp
       
print('part2: ', part2)
