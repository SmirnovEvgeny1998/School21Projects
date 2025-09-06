import sys
import re

string = ""
i = 0
for line in sys.stdin:
    if 'Exit' == line.rstrip():
        break
    string += line
splitted = string.split()

if len(splitted) != 3:
    print("Error")
else:
    while i < len(splitted):
        if len(splitted[i]) != 5:
            print("Error")
            break
        i += 1

if i == 3:
    if re.match(r'^[*][^*][^*][^*][*]$', splitted[0]) == None:
        print("False")
    elif re.match(r'^[*][*][^*][*][*]$', splitted[1]) == None:
        print("False")
    elif re.match(r'^[*][^*][*][^*][*]$', splitted[2]) == None:
        print("False")
    else:
        print("True")
