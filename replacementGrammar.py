import sys

def file_len(fname):
    with open(fname) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

def splitString(string):
    string.rstrip('\r\n')
    stringList = string.split('|')
    return stringList

def main():
    n = file_len(sys.argv[1])
    f = open(sys.argv[1], 'r')
    oldLine = '\n'
    # text to be replaced
    toReplace = ''
    for i in range(n):
        toReplace = f.readline()
    f.close()
    f = open(sys.argv[1], 'r')
    for i in range(n - 1):
        line = f.readline()
        stringList = splitString(line)
        toBeReplaced = stringList[0]
        resultWord = stringList[1]
        toReplace.replace(toBeReplaced, resultWorld)
    f.close()
    output = open('ReplaceGrammar.txt', 'w+')
    output.write(toReplace)
#print toReplace
main()