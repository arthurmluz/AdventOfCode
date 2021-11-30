import re;

f = open("1.txt", "r");

if f.mode != "r":
    exit();

instructions = re.split(", |\n", f.read());
tam = len(instructions);
				# 0 = north 1 = east 2 = south 3 = west
				# 0 = north -1 = west -2 = south -3 = east
direction = 0;
x = 0;
y = 0;
for i in range(tam-1):
    up = instructions[i];
    tam2 = len(up);
#    print(tam2);
    if( up[0] == 'R' ): direction += 1;
    if( up[0] == 'L' ): direction -= 1;
    if( direction == 4 ): direction -= 4;
    if( direction == -4 ): direction += 4;

    if( direction == 0 ): y+= int(up[1:tam2]);
    if( direction == 1 or direction == -3 ): x+= int(up[1:tam2]);
    if( direction == -1 or direction == 3): x-= int(up[1:tam2]);
    if( direction == 2 or direction == -2): y-= int(up[1:tam2]);
 #   print(instructions[i]);
#    print(direction, x, y);

print(abs(x) +abs( y));

