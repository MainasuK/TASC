//
//  theSleveOfEratosthenes.c
//  ex05_theSieveOfEratosthenes
//
//  Created by Cirno MainasuK on 2015-1-30.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include "theSleveOfEratosthenes.h"

#define MAXLENS 9999

static int table[MAXLENS];
static int primeTable[MAXLENS];
static int compositeTable[MAXLENS];

static int length;
static int left;
static int primePointer;
static int nPrime;
static int nComposite;

static void initSleve(int n);
static void getNextPrime(int primePointer);
static void removeComposite(int compositePointer);
static bool isLeft(void);
static bool isTimes(int n, int base);
static void printPrimeTable(void);

void getSlaveTable(int n) {
    initSleve(n);
    primeTable[0] = table[2];
    
    while (isLeft()) {                  //  还剩数字
        getNextPrime(primePointer);     //  圈素数
        removeComposite(primePointer);  //  这个素数还有后续的倍数的数全部画叉；
    }
    
    printPrimeTable();//  打印素数表；
}

void initSleve(int n) {
    length = n;
    left = n - 1;
    primePointer = 2;
    nPrime = 0;
    nComposite = 0;
    
    table[0] = -1;
    table[1] = -1;
    
    for (int i = 2; i <= n; i++) {
        table[i] = i;
    }
    
    for (int j = 0; j < MAXLENS; j++) {
        primeTable[j] = 0;
        compositeTable[j] = 0;
    }
}

static bool isLeft(void) {
    if (left > 0)
        return TRUE;
    return FALSE;
}

static void getNextPrime(int primePointer) {
    while (table[primePointer] == -1) {
        primePointer++;
    }
    primeTable[nPrime] = table[primePointer];
    nPrime++;
    
}

static void removeComposite(int primePointer) {
    for (int i = primePointer; i <= length; i++) {
        if (isTimes(table[i], primeTable[nPrime-1])) {
            compositeTable[nComposite] =  table[i];
            nComposite++;
            left--;
            table[i] = -1;
        }
    }
}

static bool isTimes(int n, int base) {
    if (n != -1 && n % base == 0)
        return TRUE;
    return FALSE;
}

static void printPrimeTable(void) {
    for (int i = 0; i < nPrime; i++) {
        printf("%d\n", primeTable[i]);
    }
}