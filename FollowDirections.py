import os
import re

def follow():
    mainpath = os.getcwd()
    inputfile = os.path.join(mainpath,'SampleInput.txt')
    txtfile = open(inputfile, 'r')
    output = open('FollowDirections.txt', 'w+')
    curDirection = 0
    curPos = [0, 0]
    for line in txtfile:
        textw=re.findall(r'[a-zA-Z0-9\-]+',line)
        if textw[0] == 'Move':
            if curDirection == 0:
                curPos[1] += int(textw[1])
            elif curDirection == 2:
                curPos[1] -= int(textw[1])
            if curDirection == 1:
                curPos[0] += int(textw[1])
            elif curDirection == 3:
                curPos[0] -= int(textw[1])
        elif textw[0] == 'Turn':
            if textw[1] == 'right':
                curDirection += 1
            elif textw[1] == 'left':
                curDirection -= 1
            if curDirection > 3:
                curDirection = 0
            elif curDirection < 0:
                curDirection = 3
    output.write(str(curPos[0])+','+str(curPos[1]))
    output.close()

if __name__ == '__main__':
    follow()