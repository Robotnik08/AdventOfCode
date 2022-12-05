#functions
def parseBox(s):
    x = s.split('\n')
    y = []
    for i in range(9):
        z = []
        for j in range(8):
            if x[7 - j][i*4 + 1] == " ":
                break
            z.append(x[7 - j][i*4 + 1])
        y.append(z)  
    return y

def parseInstructions(s):
    x = s.split('\n')
    del(x[:10])
    return x

def getResults1(boxes, instructions):
    for i in instructions:
        parsedInstruct = ''.join(filter(str.isdigit, i))
        appendBox = boxes[int(parsedInstruct[len(parsedInstruct) - 2]) - 1][len(boxes[int(parsedInstruct[len(parsedInstruct) - 2]) - 1]) - int(parsedInstruct[:len(parsedInstruct) - 2]):]
        appendBox.reverse()
        del(boxes[int(parsedInstruct[len(parsedInstruct) - 2]) - 1][len(boxes[int(parsedInstruct[len(parsedInstruct) - 2]) - 1]) - int(parsedInstruct[:len(parsedInstruct) - 2]):])
        boxes[int(parsedInstruct[len(parsedInstruct) - 1]) -1].extend(appendBox)
    res = ''
    for i in boxes:
        res += i[len(i) - 1]
    return res

def getResults2(boxes, instructions):
    for i in instructions:
        parsedInstruct = ''.join(filter(str.isdigit, i))
        appendBox = boxes[int(parsedInstruct[len(parsedInstruct) - 2]) - 1][len(boxes[int(parsedInstruct[len(parsedInstruct) - 2]) - 1]) - int(parsedInstruct[:len(parsedInstruct) - 2]):]
        del(boxes[int(parsedInstruct[len(parsedInstruct) - 2]) - 1][len(boxes[int(parsedInstruct[len(parsedInstruct) - 2]) - 1]) - int(parsedInstruct[:len(parsedInstruct) - 2]):])
        boxes[int(parsedInstruct[len(parsedInstruct) - 1]) -1].extend(appendBox)
    res = ''
    for i in boxes:
        res += i[len(i) - 1]
    return res


#main
f = open('input.txt', 'r')
content = f.read() 
f.close()
boxeslist = parseBox(content)
instructionslist = parseInstructions(content)
print('Result 1: ' + getResults1(boxeslist, instructionslist) + '\n')
boxeslist = parseBox(content)
print('Result 2: ' + getResults2(boxeslist, instructionslist) + '\n')