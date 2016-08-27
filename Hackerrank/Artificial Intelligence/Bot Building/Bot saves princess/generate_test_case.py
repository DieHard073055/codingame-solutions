from random import choice
from random import randint
stage_size = choice(range(3, 20, 2))
print(stage_size)
princess = [0, 0]
while(True):
    princess[0] = randint(0, stage_size-1)
    princess[1] = randint(0, stage_size-1)
    if(princess != [(stage_size-1)/2, (stage_size-1)/2]):
        break

stage = "";
for y in range(stage_size):
    for x in range(stage_size):
        if(y == princess[0] and x==princess[1]):
            stage+='p'
        elif( (y == ((stage_size-1)/2) ) and (x == ((stage_size-1)/2) ) ):
            stage+='m'
        else:
            stage+='-'
    stage+='\n'
print(stage)
