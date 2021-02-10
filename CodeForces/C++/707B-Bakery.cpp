#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int main () {

    int numberOfCities;
    int numberOfRoads;
    int numberFlourStorages;

    scanf("%i %i %i", &numberOfCities, &numberOfRoads, &numberFlourStorages);

    //road partido en info
    int *origin = (int*)malloc(sizeof(int)*numberOfRoads);
    int *destiny = (int*)malloc(sizeof(int)*numberOfRoads);
    int *km = (int*)malloc(sizeof(int)*numberOfRoads);

    // guardar caminos y costos
    for (int i = 0; i < numberOfRoads; i++) {
        scanf("%i %i %i", &origin[i], &destiny[i], &km[i]);
    }

    int flourStorage;

    // banderas de ciudades con storage
    int hasFlourStorage [100001] = {0};

    int min = INT_MAX;

    //leer ultimo renglon con booleanos si esa ciudad tiene storage
    for (int i = 0; i < numberFlourStorages; i++) {
        scanf("%i", &flourStorage);
        hasFlourStorage[flourStorage] = 1;
    }

    // comparar cada camino (origen y destino) (solo alguno de los dos  tiene que tener storage y el otro no para ser considerado el costo entre el punto de venta (bakery) y compra (flour storage))
    for (int i = 0; i < numberOfRoads; i++) {
        if (hasFlourStorage[origin[i]] + hasFlourStorage[destiny[i]] == 1) {
            // ir guardando el costo mas barato
            if (km[i] < min) {
                min = km[i];
                //printf("KM %i %i\n", hasFlourStorage[origin[i]] ,hasFlourStorage[destiny[i]]);
            }
        }
    }

    // si no hay flour storage conectado a una ciudad para vender print -1
    if (min == INT_MAX) {
        printf("-1");
    }else {
        printf("%i", min);
    }

}
