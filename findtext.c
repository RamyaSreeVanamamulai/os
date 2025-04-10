#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findtext(char *searchstr, char *filename) {
    FILE *fin;
    char buffer[1024];
    int line_number = 0;
    int found = 0;

    fin = fopen(filename, "r");
    if (!fin) {
        printf("Unable to open %s\n", filename);
        return;
    }

    while (fgets(buffer, sizeof(buffer), fin)) {
        line_number++;
        if (strstr(buffer, searchstr)) {
            if (!found) {
                printf("\n%s\n", filename);
                found = 1;
            }
            printf("%d. %s", line_number, buffer);
        }
    }

    fclose(fin);
}

#ifdef STAND_ALONE
int main(int argc, char *argv[]) {
    printf("Written by RamyaSree Vanamamulai\n");

    if (argc != 3) {
        printf("Usage: %s searchstring filename\n", argv[0]);
        return 1;
    }

    findtext(argv[1], argv[2]);
    return 0;
}
