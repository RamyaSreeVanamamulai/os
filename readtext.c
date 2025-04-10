/* This program reads and displays an ASCII text file line by line */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fin;
    char buffer[100];

    printf("Written by yourname\n");

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fin = fopen(argv[1], "r");
    if (!fin) {
        printf("Unable to open %s\n", argv[1]);
        exit(1);
    }

    while (fgets(buffer, 99, fin))
        fputs(buffer, stdout);

    fclose(fin);
    return 0;
}
