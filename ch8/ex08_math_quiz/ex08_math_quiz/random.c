//
//  random.c
//  8.3.2_randomInteger
//
//  Created by Cirno MainasuK on 2015-1-21.
//
//

/*
 * File: random.c
 * -----------------------------
 * This file implements the preliminary random.h interface.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

/*
 * Functoin: randomInteger
 * ----------------------------
 * This function first obtains a random integer in
 * the range [0..RAND_MAX] by applying four steps:
 * (1)  Generate a real number between 0 and 1.
 * (2)  Scale it to the appropriate range size.
 * (3)  Truncate the value to an integer.
 * (4)  Translate it to the appropriate starting poing.
 */

int randomInteger(int low, int high) {
    int k;
    double d;
    
    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
}


//  Function: randomReal
//  ---------------------------
//  This function first obtains a random integer in
//  the range [0..RAND_MAX] by applying two steps:
//  (1) Generate a real number between 0 and 1.
//  (2) Scale it to the appropriiate range size.

double randomReal(double low, double high) {
    double d;
    
    d = (double) rand() / ((double) RAND_MAX + 1);
    return (low + d * (high - low));
}


//  Funciton: randomChance
//  --------------------------
//  This function return TRUE or FALSE (1 or 0) under
//  chance p by compare randomReal value with p.

int randomChance(double p) {
    return (randomReal(0, 1) < p);
}



void randomize(void) {
    srand((unsigned)time(NULL));
}
