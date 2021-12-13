import hashlib

key = "bgvyzdsv"
count = part1 = 0

while(1):
    string = bytes(key+str(count), 'utf-8')
    m=hashlib.md5(string)
    m = str(m.hexdigest())
    if m[0:5] == '00000' and part1 == 0:
        part1 = count
    if m[0:6] == '000000':
        break
    count+=1
print("part1 = ", part1)
print("part2 = ", count)

