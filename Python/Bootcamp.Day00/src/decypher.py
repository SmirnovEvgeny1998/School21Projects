import sys

string = sys.argv[1]
splitted = string.split()
word = ""
i = 0

while i < len(splitted):
    word += splitted[i][0]
    i += 1
        
print(word)

