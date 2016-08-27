#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
The goal for your program is to insure that Thor reaches the light of power.
Thor moves on a map which is 40 wide by 18 high.

Once the program starts you are given:
The variable lightX: the X position of the light of power Thor must reach.
The variable lightY: the Y position of the light of power Thor must reach.
The variable initialTX: the starting X position of Thor.
The variable initialTY: the starting Y position of Thor.
Note that the coordinates (X and Y) start at the top left! This means the most top left cell has the coordinates "X=0,Y=0" and the most bottom right one has the coordinates "X=39,Y=17".

Before the end of your turn, you must output the direction in which you want Thor to go among:

N (North)
NE (North-East)
E (East)
SE (South-East)
S (South)
SW (South-West)
W (West)
NW (North-West)
Each movement makes Thor move by 1 cell in the chosen direction.

YOU WIN WHEN THOR REACHES THE LIGHT OF POWER.

YOU LOSE IF:
Thor moves off the map.

To succeed in your mission, write the following algorithm:
Save the initialTX position of Thor into a variable we'll call thorX.
Save the initialTY position of Thor into a variabble we'll call thorY.
Each game turn, initialize two variables as empty strings: directionX and directionY.
If thorX is greater than lightX, assign the value W to directionX else if thorX is less than lightX, assign the value E to directionX.
If thorY is greater than lightY, assign the value N to directionY else if thorY is less than lightY, assign the value S to directionY.
Update the thorX and thorY variables depending on the chosen directions (+1 or -1).
Output, by the end of the turn, the direction created from the concatenation of directionY and directionX. **/
int main()
{
    int LX; // the X position of the light of power
    int LY; // the Y position of the light of power
    int TX; // Thor's starting X position
    int TY; // Thor's starting Y position
    cin >> LX >> LY >> TX >> TY; cin.ignore();

    // game loop
    while (1) {
        int remainingTurns;
        cin >> remainingTurns; cin.ignore();

        int y=0, x=0;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        //move up
        if(LY < TY){ y = -1; }
        //move down
        if(LY > TY){ y = 2; }
        //move right
        if(LX > TX){ x = 1; }
        //move left
        if(LX < TX){ x = -1; }
        // A single line providing the move to be made: N NE E SE S SW W or NW
        //Move thor to the direction and update the TX TY
        if(y < 0 && x < 0){ cout << "NW" << endl; TX--;TY--; }
        else if(y < 0 && x > 0){ cout << "NE" << endl; TY--;TX++; }
        else if(y > 0 && x < 0){ cout << "SW" << endl; TY++;TX--; }
        else if(y > 0 && x > 0){ cout << "SE" << endl; TY++;TX++; }
        else if(y > 0){ cout << "S" << endl; TY++; }
        else if(y < 0){ cout << "N" << endl; TY--; }
        else if(x > 0){ cout << "E" << endl; TX++; }
        else{ cout << "W" << endl; TX--; }

    }
    return 0;
}
