targetX=(20,30)
targetY=(-10,-5)

targetX=(34, 67)
targetY=(-215,-186)

def moveProbe(x, y, speed):
    x += speed[0]
    y += speed[1]

    if speed[0] > 0:
        xv = speed[0]-1
    elif speed[0] < 0:
        xv = speed[0]+1
    else:
        xv = 0

    yv = speed[1]-1

    return x, y, (xv, yv)

highestY = 0
listTuplas = []
for i in range(1, targetX[1]+1):
    for j in range(-1000, 1000):
        highY = 0
        speed = (i,j)
        x, y = 0, 0
        while(1):
            x, y, speed = moveProbe(x, y, speed)
            if x > targetX[1] or y < targetY[0]:
                break

            if y > highY:
                highY = y

            if targetX[0] <= x <= targetX[1] and targetY[0] <= y <= targetY[1]:
                if highY > highestY:
                    highestY = highY
                if (i,j) not in listTuplas:
                    listTuplas.append((i,j))

print(highestY)
print(len(listTuplas))

 
