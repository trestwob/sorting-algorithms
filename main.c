#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <ctype.h>
#include "include/bubble.h"
#include "include/merge.h"


void usage(char **path) {
    printf("Usage program [-s algorithm name] [-n array_size] [-m <max number>]\n");
    printf("Options:\n");
    printf("-s <algorithm name> -> bubble || merge\n");
    printf("-n <number>         -> any number greater than 10\n");
    printf("-m <number>         -> any  number greater than 10\n");
    printf("Example usage -> %s -s bubble -n 20 -m 100\n", *path);
}

int validateAlgo(const char *str) {
    char *algo[] = {"bubble", "merge"};
    int arraySize = sizeof(algo) / sizeof(algo[0]);
    for (int i = 0; i < arraySize; ++i) {
        if (strcmp(str, algo[i]) == 0) return 1;
    }
    return 0;
}

int validateNumber(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

int main(int argc, char **argv) {
    int opt;
    int number = -1, MAX_RANDOM = -1;
    char *value = NULL;

    struct option long_options[] = {
        {"sort", required_argument, NULL, 's'},
        {"number", required_argument, NULL, 'n'},
        {"max", required_argument, NULL, 'm'},
        {0,0,0,0} // indicates the end of arguments
    };

    while ((opt = getopt_long(argc, argv, "s:n:m:", long_options, NULL)) != -1) {
        switch(opt) {
            case 's':
                value = optarg;
                if (!validateAlgo(value)) {
                    fprintf(stderr, "Error: Invalid sort algorithm. Must be 'bubble' or 'merge'.\n");
                    usage(&argv[0]);
                    exit(EXIT_FAILURE);
                }
                break;
            case 'n':
                if (validateNumber(optarg)) {
                    number = atoi(optarg);
                    if (number <= 10) {
                        fprintf(stderr, "Error: -n value must be greater than 10.\n");
                        usage(&argv[0]);
                        exit(EXIT_FAILURE);
                    }
                } else {
                    fprintf(stderr, "Error: -n must have a valid number.\n");
                    usage(&argv[0]);
                    exit(EXIT_FAILURE);
                }
                break;
            case 'm': 
                if (validateNumber(optarg)) {
                    MAX_RANDOM = atoi(optarg);
                    if (number <= 10) {
                        fprintf(stderr, "Error: -m value must be greater than 10.\n");
                        usage(&argv[0]);
                        exit(EXIT_FAILURE);
                    }
                } else {
                    fprintf(stderr, "Error: -n must have a valid number.\n");
                    usage(&argv[0]);
                    exit(EXIT_FAILURE);
                }
                break;
            case '?':
                usage(&argv[0]);
                exit(EXIT_FAILURE);
            default:
                usage(&argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (value && number != -1 && MAX_RANDOM != -1) {
        if (strcmp(value, "bubble") == 0) bubble(number, MAX_RANDOM);
        if (strcmp(value, "merge") == 0) merge(number, MAX_RANDOM);
    }

    return 0;
    
}
