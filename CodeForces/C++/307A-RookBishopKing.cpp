#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

    int x1;
    int y1;
    int x2;
    int y2;

    int movTorre = 0;
    int movAlfil = 0;
    int movRey = 0;

    scanf("%i %i %i %i", &x1, &y1, &x2, &y2);

    // torre, se mueve 1 en x si hay cambio + y en y si hay cambio
    int distanceX = abs(x2 - x1);
    int distanceY = abs(y2 - y1);

    if (distanceX > 0) {
        movTorre++;
    }
    if (distanceY > 0) {
        movTorre++;
    }

    // el rey el maximo de estos
    if (distanceX > distanceY) {
        movRey += distanceX;
    } else {
        movRey += distanceY;
    }

    // el alfil si es cambio par + impar no se puede, o solo un cambio impar tampoco
    if ( (((distanceX % 2) == 0) && ((distanceY % 2) != 0)) || (((distanceY % 2) == 0) && ((distanceX % 2) != 0)) ) {
        movAlfil = 0;
    }
    // sino, si esta a un paso da 1, si no da 2 pasos
    else {
        if (distanceX == distanceY) {
            movAlfil = 1;
        } else {
            movAlfil = 2;
        }
    }

    printf("%i %i %i", movTorre, movAlfil, movRey);

}
