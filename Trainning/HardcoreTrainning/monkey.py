import random

f = open('mon', 'w')

f.write('1000\n')
for i in range(1000):
	days = random.randint(10, 100)
	f.write(str(days) + ' ')
	for j in range(days):
		f.write(str(random.randint(10, 100))+" ")
	f.write("\n")
f.close()
