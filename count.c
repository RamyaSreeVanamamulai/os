#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void count(char *filename) {
    FILE *fin;
    int chars = 0, words = 0, lines = 0;
    int in_word = 0;
    int ch;

    fin = fopen(filename, "r");
    if (!fin) {
        printf("Unable to open %s\n", filename);
        return;
    }

    printf("%s\n", filename);

    while ((ch = fgetc(fin)) != EOF) {
        chars++;

        if (ch == '\n') {
            lines++;
        }

        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    printf("%d characters\n", chars);
    printf("%d words\n", words);
    printf("%d lines\n", lines);

    fclose(fin);
}

#ifdef STAND_ALONE
int main(int argc, char *argv[]) {
    printf("Written by your name \n");

    if (argc < 2) {
        printf("Usage: %s filename [filename2 ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        count(argv[i]);
        if (i < argc - 1) printf("\n");
    }

    return 0;
}
#endif
