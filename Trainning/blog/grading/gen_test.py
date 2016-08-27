import random
import sys

people = []
def get_random_name_letter():

    pick = random.randint(0,2)
    if( pick == 0 ):
        return chr( random.randint( 97, 122 ) )
    elif( pick == 1 ):
        return chr( random.randint( 65, 90 ) )
    else:
        return chr( random.randint( 48, 57 ) )

def get_random_name():
    global people
    while 1:
        name = ''
        for i in range( 10 ):
            name += get_random_name_letter()

        if name not in people:
            people.append( name )

            return name

def get_score( max ):
    return random.randint(0, max)

if( len(sys.argv ) == 2 ):
    random.seed( sys.argv[1] )
    print(20)
    for i in range( 20 ):
        print( get_random_name() + " " + \
              str( get_score(275)) + " " + \
              str( get_score(940)) + " " + \
              str( get_score(55)) + " " + \
              str( get_score(39)) + " " + \
              str( get_score(67)) + " " + \
              str( get_score(42)) + " " + \
              str( get_score(98)) + " " + \
              str( get_score(444)))
