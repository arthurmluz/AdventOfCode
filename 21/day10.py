def calculate1(chunk):
    if chunk == ')':
        return 3
    if chunk == ']':
        return 57
    if chunk == '}':
        return 1197
    if chunk == '>':
        return 25137

def calculate2(chunk):
    if chunk == '(':
        return 1
    if chunk == '[':
        return 2
    if chunk == '{':
        return 3
    if chunk == '<':
        return 4

f = open("day10.txt", "r")

part2_list = []
part1 = 0
for line in f:
    chunks = []
    corrupted = False
    for chunk in line[:-1]:
        if chunk == '[' or chunk == '{' or chunk == '(' or chunk == '<':
           chunks.append(chunk)
        else:
            a = chunks.pop()

            if (a == '(' and chunk != ')') or (a == '{' and chunk != '}') or (a == '[' and chunk != ']') or (a == '<' and chunk != '>'):
                part1 += calculate1(chunk) 
                corrupted = True
                break

    if not corrupted:
        part2 = 0
        for chunk in chunks[::-1]:
            part2 = 5 * part2 +  calculate2(chunk)
        part2_list.append(part2)

print(part1)
print(sorted(part2_list)[int(len(part2_list)/2)])
