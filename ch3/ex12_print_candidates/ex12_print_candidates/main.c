//
//  main.c
//  ex12_print_candidates
//
//  Created by Cirno MainasuK on 2015-1-8.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>
#define NUM 4

// a struct of two parameter name & votes
typedef struct Candidates {
    char *name;
    int votes;
} Candidates;

int main(int argc, const char * argv[]) {
    
    // use struct save four candidates info
    Candidates table[NUM] = {
        "Clinton", 3372,
        "Brown", 596,
        "Tsongas", 209,
        "Other", 74
    };
    
    for (int i = 0; i < NUM; i++) {
        printf("%-15.15s%4d\n", table[i].name, table[i].votes);
    }
    
    return 0;
}
