//
//  random.h
//  8.3.2_randomInteger
//
//  Created by Cirno MainasuK on 2015-1-21.
//
//

/*
 * File: random.h
 * ----------------------------
 * This file contains a preliminary version of a library
 * interface to produce pseudo-random numbers.
 */

#ifndef ____3_2_randomInteger__random__
#define ____3_2_randomInteger__random__


/*
 * Function: randomInteger
 * Usage: n = randomInteger(low, high);
 * ------------------------------
 * This function returns a random integer in the range 
 * low to hight, inclusive.
 */

int randomInteger(int low, int high);


//  Function: randomReal
//  Usage: d = randomReal(low, high);
//  ----------------------------
//  This function returns a random real number in the
//  range low to high, inclusive

double randomReal(double low, double high);


//  Function: randomChance
//  Usage: bool = randomChance(chance);
//  ---------------------------
//  This function returns a int value (1)RUE or (0)FALSE.
//  It's has (p) probility return TRUE.

int randomChance(double p);

#endif /* defined(____3_2_randomInteger__random__) */
