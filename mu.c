#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes from other files
void findtext(char *searchstr, char *filename);
void right(int a, int b, int c);
void count(char *filename);

int main(int argc, char *argv[]) {
    printf("Written by your name\n");

    if (argc < 2) {
        printf("Usage: %s [-f searchstr file] [-r n1 n2 n3] [-c file1 [file2 ...]]\n", argv[0]);
        return 1;
    }

    int i = 1;
    while (i < argc) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'f':
                    if (i + 2 >= argc) {
                        printf("Error: -f requires searchstring and filename\n");
                        i++;
                        break;
                    }
                    findtext(argv[i + 1], argv[i + 2]);
                    i += 3;
                    break;

                case 'r':
                    if (i + 3 >= argc) {
                        printf("Error: -r requires three numbers\n");
                        i++;
                        break;
                    }
                    right(atoi(argv[i + 1]), atoi(argv[i + 2]), atoi(argv[i + 3]));
                    i += 4;
                    break;

                case 'c':
                    if (i + 1 >= argc) {
                        printf("Error: -c requires at least one filename\n");
                        i++;
                        break;
                    }
                    i++;
                    // Process all subsequent arguments until next flag or end
                    while (i < argc && argv[i][0] != '-') {
                        count(argv[i]);
                        printf("\n");
                        i++;
                    }
                    break;

                default:
                    printf("Invalid argument: %s", argv[i]);
                    // Print all parameters until next flag
                    i++;
                    while (i < argc && argv[i][0] != '-') {
                        printf(" %s", argv[i]);
                        i++;
                    }
                    printf("\n");
                    break;
            }
        } else {
            printf("Error: Expected flag argument starting with '-', got %s\n", argv[i]);
            i++;
        }
    }

 return 0;
