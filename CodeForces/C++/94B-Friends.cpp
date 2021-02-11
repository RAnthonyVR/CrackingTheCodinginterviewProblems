/* By: Ricardo Antonio Vazquez Rodriguez
Problem 94B codeforces "Friends"*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


int main () {

    int numRelationships;

    int numberOfFriends = 5;

    scanf("%i", &numRelationships);

    int friend1;
    int friend2;

    // matriz de adjacencia
    int relationships [5] [5];

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            relationships [row] [col] = 0;
        }
    }

    for (int i = 0; i < numRelationships; i++) {
        scanf("%i %i", &friend1, &friend2);
        //index
        friend1--;
        friend2--;
        // bidirecitonal
        relationships[friend1][friend2] = 1;
        relationships[friend2][friend1] = 1;
    }

    int numberParwiseFriends = 0;

    int ans = 0;

    // three persons relationships
    for (int person1 = 0; person1 < numberOfFriends; person1++) {

        for (int person2 = person1 + 1; person2 < numberOfFriends; person2++) {
            for (int person3 = person2 + 1; person3 < numberOfFriends; person3++) {
                if ((relationships[person1][person2] + relationships[person2][person3] + relationships[person1][person3]) == 3) {
                    ans = 1;
                } else if ((relationships[person1][person2] + relationships[person2][person3] + relationships[person1][person3]) == 0) {
                    ans = 1;
                }
            }
        }
    }

    // if none of them
    if (ans == 0) {
        printf("FAIL");
    } else {
        printf("WIN");
    }

    return 0;
}
