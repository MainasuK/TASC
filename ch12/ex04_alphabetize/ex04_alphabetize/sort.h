//
//  sort.h
//  ex04_alphabetize
//
//  Created by Cirno MainasuK on 2015-2-1.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//
//  File: sort.h
//  -------------
//  This file provides an interface to a simple procedure
//  for sorting an integer array into increasing order.

#ifndef __ex04_alphabetize__sort__
#define __ex04_alphabetize__sort__

#include <stdio.h>


//  Function: sortIntegerArray
//  Usage: sortIntegerArray(array, n);
//  ------------------------------
//  This function sorts the first n elements in array into
//  increasing numerical order. In order to use this procedure,
//  you must declare the array in the calling program and pass
//  the effective number of elements as the parameter n.
//  In most cases the array will have a larger allocated
//  size.

void sortIntegerArray(int array[], int n);
void sortAlphabetize(char *array[], int n);
#endif /* defined(__ex04_alphabetize__sort__) */
