#!usr/bin/python27
import random

tri_size = 60
s = ""

for i in xrange(0, tri_size):
	for j in xrange(0, i+1):
		s = s + str(random.randint(0, 9)) + " "

	s= s+'\n'

print s	 
