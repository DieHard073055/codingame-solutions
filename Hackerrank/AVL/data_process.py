file = open('data', 'r')
x = ""
i=0
for line in file:
    i+=1
    x+=str(line.split(',')[0]) + " "
file.close()
print(i)
print(x)
