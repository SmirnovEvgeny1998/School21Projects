import sys

string = ""
for line in sys.stdin:
    if 'Exit' == line.rstrip():
        break
    string += line
length = sys.argv[1]
splitted = string.split()
i = 0

while i < length and i < len(splitted):
    if not splitted[i].startswith("00000"):
        splitted.pop(i)
    elif splitted[i].startswith("000000"):
        splitted.pop(i)
    elif len(splitted[i]) != 32:
        splitted.pop(i)
    else:
        i += 1
        
i = 0
while i < len(splitted):
    print(splitted[i])
    i += 1
