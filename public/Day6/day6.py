#functions
def output (s, size):
    for i in range(len(s)):
        if i < size: continue
        if isUnique(s[i-size:i]): return i
    return 'not found!'

def isUnique (s):
    for i in range(len(s)):
        for j in range(len(s)):
            if i == j: continue
            if s[i] == s[j]: return False
    return True
#main
f = open('input.txt', 'r')
content = f.read() 
f.close()
print(output(content, 4))
print(output(content, 14))