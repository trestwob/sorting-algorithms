#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "include/bubble.h"

void usage(char **path) {
    printf("Usage: \n%s [-s <algorithm name>]\n[-n <size of array]\n[-m <max number>]\n -n and -m arguments should be greater than 10\nExample usage -> %s -s bubble -n 100 -m 100", *path, *path);
}
// make this command line argument better
int main(int argc, char **argv) {
    if (argc < 7 || argc > 7 ) {
        usage(&argv[0]);
        exit(1);
    }

    int ind;
    int c;
    char *value = NULL;
    int number = 100;
    int maxVal = 100;
    while ((c = getopt (argc, argv, "s:n:m:")) != -1) {
        switch (c) {
            case 's':
                value = optarg;
            break;
            case 'n':
            number = atoi(optarg);
            break;
            case 'm':
            maxVal = atoi(optarg);
            break;
            default:
            abort(); 
        }
    }

    if (strcmp(value, "bubble") == 0 && number > 10 && maxVal > 10) {
        bubble(number, maxVal);
    } else {
        usage(&argv[0]);
        exit(1);
    }
    
    for (ind = optind; ind < argc; ind++) {
        printf("Invalid arguments provided. %s\n", argv[ind]);
        usage(&argv[0]);
    }

    return 0;
}
