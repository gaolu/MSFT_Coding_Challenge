import os

def match():
    mainpath = os.getcwd()
    inputfile = os.path.join(mainpath,'SampleInput.txt')
    txtfile = open(inputfile, 'r')
    num = int(txtfile.readline())
    res = False
    output = open('TextQueryMatch.txt', 'w+')
    output.write(str(num))
    output.write('\n')
    while (num > 0) :
        res = False
        query = txtfile.readline()[:-1]
        text = txtfile.readline()[:-1]
        for i in xrange(len(text)):
            if text[i].lower() == query[0].lower() and (i == 0 or text[i-1] == ' '):
                res = startmatch(query, text, i)
        if res:
            output.write('true')
        else:
            output.write('false')
        output.write('\n')
        num -= 1
    output.close()



def startmatch(query, text, startpos):
    i = 0
    while (i < len(query)):
        if query[i].lower() == text[startpos].lower():
            startpos += 1
            i += 1
        elif text[startpos] == ' ':
            startpos += 1
        else:
            return False
    return True

if __name__ == '__main__':
    match()