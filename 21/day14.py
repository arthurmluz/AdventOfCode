import sys

f = open(sys.argv[1], 'r')
template = "PFVKOBSHPSPOOOCOOHBP"

rules = {}
# insert the string on TEMPLATE, and the input file should be only the rules
for line in f:
    line = list(map(str.strip, line[:-1].split("->")))
    rules[line[0]] = line[1]
    
template_dic = {}
for i in range(len(template)-1):
    dupla = template[i]+template[i+1]
    template_dic[dupla] = 1 + template_dic[dupla] if dupla in template_dic else 1

def magic(steps, template_dic):
    for step in range(steps):
        new_template = {}
        count = {}
        for dupla in template_dic:
            new_dupla = dupla[0] + rules[dupla]
            new_template[new_dupla] = 1*template_dic[dupla] + new_template[new_dupla] if new_dupla in new_template else 1*template_dic[dupla]
            new_dupla = rules[dupla] + dupla[1]
            new_template[new_dupla] = 1*template_dic[dupla] + new_template[new_dupla] if new_dupla in new_template else 1*template_dic[dupla]
            
        template_dic = new_template
    return template_dic

def countChars():
    count = {}
    for dupla in template_dic:
        count[dupla[0]] = 1*template_dic[dupla] + count[dupla[0]] if dupla[0] in count else 1*template_dic[dupla]
        count[dupla[1]] = 1*template_dic[dupla] + count[dupla[1]] if dupla[1] in count else 1*template_dic[dupla]

    menor = sys.maxsize
    maior = 0
    for num in count:
        count[num] = round(count[num]/2)
        if count[num] > maior:
            maior = count[num]

        if count[num] < menor:
            menor = count[num]

    return maior - menor

template_dic = magic(10, template_dic)
print("part1: ", countChars()-1)

template_dic = magic(40, template_dic)
print("part2: ", countChars()-1)

