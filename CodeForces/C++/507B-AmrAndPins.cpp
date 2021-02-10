#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

    int radius;
    int inititalX;
    int inititalY;
    int finalX;
    int finalY;

    scanf("%i %i %i %i %i", &radius, &inititalX, &inititalY, &finalX, &finalY);

    //distancia entre dos puntos
    int movementInX = abs(finalX - inititalX);
    int movementInY = abs(finalY - inititalY);

    float distance =  ceil (sqrt(pow(movementInX, 2) + pow(movementInY, 2)));

    //Un paso recorre dos radios (un diametro)
    int diameterDistance = radius * 2;
    // redondear arriba para que no falten pasos para llegar
    int numberOfSteps = ceil (distance / diameterDistance);

    printf("%i", numberOfSteps);

}
