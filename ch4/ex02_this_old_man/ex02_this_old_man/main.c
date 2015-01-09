//
//  main.c
//  ex02_this_old_man
//
//  Created by Cirno MainasuK on 2015-1-9.
//  Copyright (c) 2015年 Cirno MainasuK. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    for (int i = 1; i <= 10; i++) {
        char *c;
        
        switch (i) {
            case 1:
                c = "thumb";
                break;
            case 2:
                c = "shoe";
                break;
            case 3:
                c = "knee";
                break;
            case 4:
                c = "door";
                break;
            case 5:
                c = "hive";
                break;
            case 6:
                c = "sticks";
                break;
            case 7:
                c = "heaven";
                break;
            case 8:
                c = "pate";
                break;
            case 9:
                c = "spine";
                break;
            case 10:
                c = "skin";
                break;
        }
        
        printf("This old man, he played %d.\n", i);
        printf("He played knick-knack on my %s\n", c);
        printf("With a Knick-Knac, paddy-whack,\n");
        printf("Give your dog a hone.\n");
        printf("This old man came rolling home.\n");
    }
    return 0;
}
