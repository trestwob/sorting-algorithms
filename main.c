#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "include/bubble.h"

void usage(char **path) {
    printf("Usage: %s [-s bubble]\n", *path);
}

int main(int argc, char **argv) {
    int ind;
    int c;
    while ((c = getopt (argc, argv, "s:")) != -1) {
        switch (c) {
            case 's':
            if (strcmp(optarg, "bubble") == 0) bubble();
            break;
            default:
            abort(); 
        }
    }

    for (ind = optind; ind < argc; ind++) {
        printf("Invalid arguments provided. %s\n", argv[ind]);
        usage(&argv[0]);
    }

    return 0;
}
